#include <gb/cgb.h>
#include <gb/gb.h>
#include <rand.h>

#include "background.c"
#include "background_a.c"
#include "main_tile_set_p.c"
#include "sprites_p.c"
#include "windows.c"

#define MAX_ASTEROIDS 4
#define TOTAL_LIVES 5

const int xMax = DEVICE_SCREEN_PX_WIDTH - 4;
const int xMin = 12;
const int yMax = DEVICE_SCREEN_PX_HEIGHT + 4;
const int yMin = 20;

BOOLEAN hideFire = TRUE;
BOOLEAN stopBG = TRUE;
BOOLEAN xMove = TRUE;
BOOLEAN startAsteroid = FALSE;
BOOLEAN resetAsteroid = FALSE;
BOOLEAN corrAsteroid = FALSE;
BOOLEAN collision = FALSE;

uint8_t asteroids[2][MAX_ASTEROIDS];
uint8_t propAsteroid[3][MAX_ASTEROIDS];
uint8_t world[2];
uint8_t fire[2];
uint8_t numLives = TOTAL_LIVES;
uint8_t numAsteroids = 0;
uint8_t spriteCount = 0;
uint8_t aux = 0;
uint8_t spCountAst;
uint8_t spCountTile;
uint8_t currAsteroid;
uint8_t bgMoveDir;
uint8_t currSprite;
uint8_t randNum;
uint8_t randSprite;
uint8_t randPos;
uint8_t randTime;
uint8_t spWorld;
uint8_t spFire;
uint8_t spExplosion;
uint8_t spHeart[TOTAL_LIVES];
uint8_t spAsteroid[MAX_ASTEROIDS];

int timeAsteroid = 0;
int timeAsteroid2 = 0;
int valPosAsteroid;

int idxBkgTiles = 72;
int idxWinTiles = 10;
int idxSprites = 16;

void init();
void updateSwitches();
void helloPrep();
void helloStart();
void bkgTransition(uint8_t);
void gameOver();
void checkInput();
void spriteMove();
void asteroidControl();
void asteroidMove();
void bgMove();
void explosion();
void removeLives();
void resetVariables();
void setBkgPalette(uint8_t, uint8_t, uint8_t, uint8_t, unsigned char[]);
void performant_delay(uint8_t);
BOOLEAN collisionCheck(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);

void main() {
    init();

    while (1) {
        checkInput();       // Check for user input
        spriteMove();       // Call function to move sprites
        bgMove();           // Call function to move background
        asteroidControl();  // Control asteroids creation and movement
        asteroidMove();     // Move asteroids
        updateSwitches();   // Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
        wait_vbl_done();    // Wait until VBLANK to avoid corrupting memory
    }
}

void init() {
    // Load background and sprite palettes
    aux = 0;
    for (uint8_t i = 0; i < 8; i++) {
        set_bkg_palette(i, 1, &main_tile_set_p[aux]);
        set_sprite_palette(i, 1, &sprites_p[aux]);
        aux += 4;
    }

    // Load background, windows and sprite tiles to vram
    set_bkg_data(0, idxBkgTiles, MainTileSet);
    set_win_data(idxBkgTiles, idxWinTiles, Windows);
    set_sprite_data(0, idxSprites, Sprites);

    // Set heart palette and tile
    for (uint8_t i = 0; i < numLives; i++) {
        spHeart[i] = spriteCount;
        set_sprite_prop(spriteCount, 2);  // Heart - Palette 2
        set_sprite_tile(spHeart[i], 15);  // Set tile
        spriteCount++;
    }

    // Set explosion palette
    spExplosion = spriteCount;
    set_sprite_prop(spriteCount, 4);
    spriteCount++;

    // Set asteroids palette
    for (uint8_t i = 0; i < MAX_ASTEROIDS; i++) {
        spAsteroid[i] = spriteCount;
        set_sprite_prop(spriteCount, 3);
        spriteCount++;
    }

    // Set world palette and tile
    spWorld = spriteCount;
    set_sprite_prop(spriteCount, 1);
    set_sprite_tile(spWorld, 0);
    spriteCount++;

    // Set fire palette
    spFire = spriteCount;
    set_sprite_prop(spriteCount, 2);
    spriteCount++;

    DISPLAY_ON;  // Turn on the display

    NR52_REG = 0x8F;  // Turn on the sound
    NR51_REG = 0x11;  // Enable the sound channels
    NR50_REG = 0x77;  // Increase the volume to its max

    initrand(sys_time);  // Start randon seed

    helloPrep();  // Call start screen
}

void updateSwitches() {
    HIDE_WIN;      // Hide windows
    SHOW_SPRITES;  // Show sprites
    SHOW_BKG;      // Show background
}

void helloPrep() {
    // Set start screen palette and tiles
    setBkgPalette(0, 0, FullWidth, FullHeight, HelloWorld_a);  // Set bkg palette
    set_bkg_tiles(0, 0, FullWidth, FullHeight, HelloWorld);    // Set bkg tiles
    move_bkg(0, 0);                                            // Move background to the 0x 0y position

    // Wait for start button press and do initialization
    waitpad(J_START);
    helloStart();
}

// TO-DO: Add some dialog on the start
void helloStart() {
    // Call transition function
    bkgTransition(0);

    // Set universe palette and tiles
    setBkgPalette(0, 0, UniverseWidth, UniverseHeight, Universe_a);
    set_bkg_tiles(0, 0, UniverseWidth, UniverseHeight, Universe);

    // Start on screen center
    world[0] = (DEVICE_SCREEN_PX_WIDTH / 2) + 4;
    world[1] = (DEVICE_SCREEN_PX_HEIGHT / 2) + 4;

    // Put world sprite on starting location
    move_sprite(spWorld, world[0], world[1]);

    // Put heart sprites on starting location
    aux = 12;
    for (uint8_t i = 0; i < numLives; i++) {
        move_sprite(spHeart[i], aux, 20);
        aux += 10;
    }
}

void bkgTransition(uint8_t type) {
    // Transition type 0 - Game start
    if (type == 0) {
        // Move bg to the right
        for (uint8_t i = 0; i < 15; i++) {
            delay(30);
            set_bkg_tiles(i, 0, FullWidth, FullHeight, HelloWorld);
        }

        setBkgPalette(0, 0, FullWidth, FullHeight, BlackScreen_a);  // Set bkg palette

        // Transitions
        set_bkg_tiles(0, 0, FullWidth, FullHeight, BlankScreen);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran1);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran2);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran3);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran4);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, BlackScreen);
        delay(100);
    }

    // Transition type 1 - Game over
    if (type == 1) {
        setBkgPalette(0, 0, FullWidth, FullHeight, BlackScreen_a);  // Set bkg palette

        // Transitions
        set_bkg_tiles(0, 0, FullWidth, FullHeight, BlackScreen);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran4);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran3);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran2);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, Tran1);
        delay(100);
        set_bkg_tiles(0, 0, FullWidth, FullHeight, BlankScreen);
        delay(100);
    }
}

void gameOver() {
    // Do some blinking with the sprites
    for (uint8_t i = 0; i < 6; i++) {
        performant_delay(5);
        HIDE_SPRITES;
        performant_delay(5);
        SHOW_SPRITES;
    }

    // Wait and actually hide sprites
    performant_delay(10);
    hide_sprite(spFire);
    hide_sprite(spWorld);
    for (uint8_t i = 0; i < MAX_ASTEROIDS; i++) {
        hide_sprite(spAsteroid[i]);
    }

    performant_delay(10);
    move_bkg(0, 0);    // Move background to the 0x 0y position
    bkgTransition(1);  // Call transition function

    // Reset control variables
    resetVariables();

    // Set game over screen
    setBkgPalette(0, 0, FullWidth, FullHeight, HelloWorld_a);
    set_bkg_tiles(0, 0, FullWidth, FullHeight, GameOver);

    // Wait for start button
    waitpad(J_START);

    // Call start screen
    performant_delay(10);
    helloPrep();
}

void checkInput() {
    // Current tile state of fire sprite
    currSprite = get_sprite_tile(2);
    hideFire = FALSE;
    stopBG = FALSE;

    // Current state of joypad
    switch (joypad()) {
        case J_UP:

            if (world[1] > yMin) {
                world[1]--;
            }

            xMove = FALSE;

            if (currSprite != 1) {
                set_sprite_tile(spFire, 1);  // Fire up
            }

            fire[0] = world[0];
            fire[1] = world[1] + 9;

            break;

        case J_DOWN:

            if (world[1] < yMax) {
                world[1]++;
            }

            xMove = FALSE;

            if (currSprite != 2) {
                set_sprite_tile(spFire, 2);  // Fire down
            }

            fire[0] = world[0];
            fire[1] = world[1] - 9;

            break;

        case J_LEFT:

            if (world[0] > xMin) {
                world[0]--;
            }

            xMove = TRUE;

            if (currSprite != 3) {
                set_sprite_tile(spFire, 3);  // Fire left
            }

            fire[0] = world[0] + 9;
            fire[1] = world[1];

            break;

        case J_RIGHT:

            if (world[0] < xMax) {
                world[0]++;
            }

            xMove = TRUE;

            if (currSprite != 4) {
                set_sprite_tile(spFire, 4);  // Fire right
            }

            fire[0] = world[0] - 9;
            fire[1] = world[1];

            break;

        default:
            hideFire = TRUE;
            stopBG = TRUE;
            break;
    }
}

void spriteMove() {
    // Move the sprite to the position of X and Y
    move_sprite(spWorld, world[0], world[1]);

    if (hideFire) {
        hide_sprite(spFire);
    } else {
        move_sprite(spFire, fire[0], fire[1]);
    }
}

void asteroidControl() {
    if (startAsteroid) {
        if (numAsteroids < MAX_ASTEROIDS || resetAsteroid) {
            // Generate randon numbers
            randNum = rand();
            randSprite = rand();
            randPos = rand();

            // If asteroid is a new one (not destroyed)
            if (!resetAsteroid) {
                currAsteroid = numAsteroids;
            }

            // Define screen side for asteroid start
            if (randNum < 64) {  // Asteroid comes from up
                valPosAsteroid = (randPos * DEVICE_SCREEN_PX_WIDTH) / 255;
                asteroids[0][currAsteroid] = valPosAsteroid;
                asteroids[1][currAsteroid] = 0;
                propAsteroid[0][currAsteroid] = 0;

            } else if (randNum < 128) {  // Asteroid comes from bottom
                valPosAsteroid = (randPos * DEVICE_SCREEN_PX_WIDTH) / 255;
                asteroids[0][currAsteroid] = valPosAsteroid;
                asteroids[1][currAsteroid] = DEVICE_SCREEN_PX_HEIGHT;
                propAsteroid[0][currAsteroid] = 1;

            } else if (randNum < 192) {  // Asteroid comes from left
                valPosAsteroid = (randPos * DEVICE_SCREEN_PX_HEIGHT) / 255;
                asteroids[0][currAsteroid] = 0;
                asteroids[1][currAsteroid] = valPosAsteroid;
                propAsteroid[0][currAsteroid] = 2;

            } else {  // Asteroid comes from right
                valPosAsteroid = (randPos * DEVICE_SCREEN_PX_HEIGHT) / 255;
                asteroids[0][currAsteroid] = DEVICE_SCREEN_PX_WIDTH;
                asteroids[1][currAsteroid] = valPosAsteroid;
                propAsteroid[0][currAsteroid] = 3;
            }

            // Define sprite variant
            if (randSprite < 85) {
                propAsteroid[1][currAsteroid] = 0;  // Sprite 1 - Left OR Up
            } else if (randSprite < 170) {
                propAsteroid[1][currAsteroid] = 1;  // Sprite 2 - Right OR Down
            } else {
                propAsteroid[1][currAsteroid] = 2;  // Sprite 3 - Center
            }

            switch (propAsteroid[0][currAsteroid]) {
                case 0:  // Asteroid comes from up
                    switch (propAsteroid[1][currAsteroid]) {
                        case 0:
                            propAsteroid[2][currAsteroid] = 8;
                            break;
                        case 1:
                            propAsteroid[2][currAsteroid] = 5;
                            break;
                        case 2:
                            propAsteroid[2][currAsteroid] = 10;
                            break;
                        default:
                            break;
                    }
                    break;
                case 1:  // Asteroid comes from bottom
                    switch (propAsteroid[1][currAsteroid]) {
                        case 0:
                            propAsteroid[2][currAsteroid] = 7;
                            break;
                        case 1:
                            propAsteroid[2][currAsteroid] = 6;
                            break;
                        case 2:
                            propAsteroid[2][currAsteroid] = 9;
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:  // Asteroid comes from left
                    switch (propAsteroid[1][currAsteroid]) {
                        case 0:
                            propAsteroid[2][currAsteroid] = 7;
                            break;
                        case 1:
                            propAsteroid[2][currAsteroid] = 8;
                            break;
                        case 2:
                            propAsteroid[2][currAsteroid] = 12;
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:  // Asteroid comes from right
                    switch (propAsteroid[1][currAsteroid]) {
                        case 0:
                            propAsteroid[2][currAsteroid] = 6;
                            break;
                        case 1:
                            propAsteroid[2][currAsteroid] = 5;
                            break;
                        case 2:
                            propAsteroid[2][currAsteroid] = 11;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

            spCountAst = spAsteroid[currAsteroid];        // Determine asteroid sprite
            spCountTile = propAsteroid[2][currAsteroid];  // Determines the position tile
            set_sprite_tile(spCountAst, spCountTile);     // Set asteroid sprite

            if (resetAsteroid) {
                resetAsteroid = FALSE;
            } else {
                numAsteroids++;
            }

            startAsteroid = FALSE;
        }
    }

    timeAsteroid++;
    timeAsteroid2++;

    randTime = rand();

    // Create a anew asteroid
    if ((timeAsteroid > 300 + randTime) && (numAsteroids < MAX_ASTEROIDS)) {
        startAsteroid = TRUE;
        timeAsteroid = 0;
    }
}

// TO-DO: Add velocity control?
void asteroidMove() {
    for (uint8_t i = 0; i < numAsteroids; i++) {
        spCountAst = spAsteroid[i];
        move_sprite(spCountAst, asteroids[0][i], asteroids[1][i]);

        // If there is a colision between the asteroid and the player
        collision = collisionCheck(world[0], world[1], 8, 8, asteroids[0][i], asteroids[1][i], 8, 8);

        if (collision) {
            explosion();    // Call function to do the explosion
            removeLives();  // Remove one live from the player

            resetAsteroid = TRUE;
            startAsteroid = TRUE;
            currAsteroid = i;

            continue;
        }

        if (asteroids[0][i] > DEVICE_SCREEN_PX_WIDTH || asteroids[1][i] > DEVICE_SCREEN_PX_HEIGHT) {
            randNum = rand();

            // Define if asteroid will be reseted
            if (randNum < 5 || randNum > 250) {
                resetAsteroid = TRUE;
                startAsteroid = TRUE;
                currAsteroid = i;

                continue;
            }
        }

        // Determine movement increments based on the type of sprite/movement
        switch (propAsteroid[2][i]) {
            case 5:  // Right top
                asteroids[0][i]--;
                asteroids[1][i]++;
                break;
            case 6:  // Right bottom
                asteroids[0][i]--;
                asteroids[1][i]--;
                break;
            case 7:  // Left bottom
                asteroids[0][i]++;
                asteroids[1][i]--;
                break;
            case 8:  // Left top
                asteroids[0][i]++;
                asteroids[1][i]++;
                break;
            case 9:  // Center bottom
                asteroids[1][i]--;
                break;
            case 10:  // Center top
                asteroids[1][i]++;
                break;
            case 11:  // Right center
                asteroids[0][i]--;
                break;
            case 12:  // Left center
                asteroids[0][i]++;
                break;
            default:
                break;
        }

        // Corrections to compensate background movement
        if (!stopBG && corrAsteroid) {
            switch (bgMoveDir) {
                case 0:  // Background moving to the left
                    asteroids[0][i]--;
                    break;
                case 1:  // Background moving to the right
                    asteroids[0][i]++;
                    break;
                case 2:  // Background moving to the top
                    asteroids[1][i]--;
                    break;
                case 3:  // Background moving to the bottom
                    asteroids[1][i]++;
                    break;
                default:
                    break;
            }
        }
    }
}

void bgMove() {
    // Move the background if the player is on the edge of the map
    if (!stopBG) {
        if ((world[0] >= xMax) && xMove) {  // Right limit of screen, move bkg left
            scroll_bkg(1, 0);
            bgMoveDir = 0;
            corrAsteroid = TRUE;

        } else if ((world[0] <= xMin) && xMove) {  // Left limit of screen, move bkg right
            scroll_bkg(-1, 0);
            bgMoveDir = 1;
            corrAsteroid = TRUE;

        } else if ((world[1] >= yMax) && !xMove) {  // Bottom limit of screen, move bkg up
            scroll_bkg(0, 1);
            bgMoveDir = 2;
            corrAsteroid = TRUE;

        } else if ((world[1] <= yMin) && !xMove) {  // Top limit of screen, move bkg down
            scroll_bkg(0, -1);
            bgMoveDir = 3;
            corrAsteroid = TRUE;

        } else {
            corrAsteroid = FALSE;
        }
    }
}

void explosion() {
    // Hide the asteroid
    delay(10);
    hide_sprite(spCountAst);

    // Set explosion 1 and move a little
    set_sprite_tile(spExplosion, 13);
    move_sprite(spExplosion, world[0], world[1]);
    move_sprite(spExplosion, world[0] + 1, world[1]);
    move_sprite(spExplosion, world[0] - 1, world[1]);
    delay(50);

    // Set explosion 2 and move a little
    set_sprite_tile(spExplosion, 14);
    move_sprite(spExplosion, world[0], world[1]);
    move_sprite(spExplosion, world[0], world[1] + 1);
    move_sprite(spExplosion, world[0], world[1] - 1);
    move_sprite(spExplosion, world[0], world[1]);
    delay(50);
    hide_sprite(spExplosion);  // Hide explosion
}

void removeLives() {
    numLives--;

    hide_sprite(spHeart[numLives]);  // Hide heart sprite

    if (numLives == 0) {
        performant_delay(5);
        gameOver();
    }
}

void resetVariables() {
    numLives = TOTAL_LIVES;
    numAsteroids = 0;
    timeAsteroid = 0;
    timeAsteroid2 = 0;
    aux = 0;
}

void setBkgPalette(uint8_t xMin, uint8_t yMin, uint8_t xMax, uint8_t yMax, unsigned char map[]) {
    VBK_REG = VBK_ATTRIBUTES;                    // Select VRAM bank 1
    set_bkg_tiles(xMin, yMin, xMax, yMax, map);  // Set bkg atributes
    VBK_REG = VBK_TILES;                         // Swittch back to VRAM bank 0
}

void performant_delay(uint8_t numloops) {
    for (uint8_t i = 0; i != numloops; i++) {
        wait_vbl_done();
    }
}

BOOLEAN collisionCheck(uint8_t x1, uint8_t y1, uint8_t w1, uint8_t h1, uint8_t x2, uint8_t y2, uint8_t w2, uint8_t h2) {
    if ((x1 < (x2 + w2)) && ((x1 + w1) > x2) && (y1 < (h2 + y2)) && ((y1 + h1) > y2)) {
        return TRUE;
    } else {
        return FALSE;
    }
}