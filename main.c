/*

 Hello World game. Main game file.

 18-Nov-2022    SrCamarda   Initial version with change comments
 11-Jan-2023    SrCamarda   Add counter of astronauts saved

*/

#include <gb/cgb.h>
#include <gb/gb.h>
#include <rand.h>

#include "art/background.c"       // Backgrounds maps
#include "art/background_a.c"     // Background atributtes
#include "art/characters.c"       // Letters and numbers
#include "art/main_tile_set_p.c"  // Background tiles
#include "art/sprites_p.c"        // Sprites
#include "art/win_tile_set.c"     // Windows tiles
#include "art/windows.c"          // Windows maps
#include "cbtfx.c"                // Sound driver
#include "sfx.c"                  // Sound effects
#include "strings.c"              // Dialog string

// Constants
#define TOTAL_ASTEROIDS 10
#define TOTAL_ASTRONAUTS 10
#define TOTAL_LIVES 5

const int xMax = DEVICE_SCREEN_PX_WIDTH - 4;
const int xMin = 12;
const int yMax = DEVICE_SCREEN_PX_HEIGHT + 4;
const int yMin = 20;

const int uniPxWidth = UniverseWidth * 8;
const int uniPxHeight = UniverseHeight * 8;

const uint8_t firstRowAdr = 0xd0;
const uint8_t secondRowAdr = 0xe0;
const uint8_t blackTileAdr = 0xf0;
const uint8_t charOffset = 32;

// Boolean vars
BOOLEAN hideFire = TRUE;
BOOLEAN stopBG = TRUE;
BOOLEAN xMove = TRUE;
BOOLEAN startAsteroid = FALSE;
BOOLEAN resetAsteroid = FALSE;
BOOLEAN corrBgMove = FALSE;
BOOLEAN collision = FALSE;
BOOLEAN resetAstronaut = TRUE;
BOOLEAN keyDown = FALSE;

// Integer vars
int idxBkgTiles = 72;
int idxWinTiles = 9;
int idxSprites = 19;
int timeAsteroid = 0;

// Unsigned integer vars
uint8_t asteroids[2][TOTAL_ASTEROIDS];
uint8_t propAsteroid[3][TOTAL_ASTEROIDS];
uint8_t astronaut[2];
uint8_t world[2];
uint8_t fire[2];
uint8_t numLives = TOTAL_LIVES;
uint8_t numAsteroids = 0;
uint8_t maxAsteroids = 6;
uint8_t numAstronauts = 0;
uint8_t maxAstronauts = 6;
uint8_t spriteCount = 0;
uint8_t currAsteroid;
uint8_t currSprite;
uint8_t bgMoveDir;
uint8_t randNum;
uint8_t randNum2;
uint8_t spWorld;
uint8_t spFire;
uint8_t spExplosion;
uint8_t spAstronaut;
uint8_t spAstronautCount;
uint8_t spCountBg;
uint8_t spHeart[TOTAL_LIVES];
uint8_t spAsteroid[TOTAL_ASTEROIDS];
uint8_t openDiaLines;
uint8_t aux = 0;

// Functions
void init();
void updateSwitches();
void helloPrep();
void helloStart();
void bkgTransition(uint8_t);
void gameOver();
void gameWin();
void checkInput();
void spriteMove();
void asteroidControl();
void asteroidMove();
void astronautControl();
void bgMove();
void explosion();
void removeLives();
void resetVariables();
void performantDelay(uint8_t);
void setBkgPalette(uint8_t, uint8_t, uint8_t, uint8_t, unsigned char[]);
uint8_t showDialog(unsigned char[][MAX_STRING_SIZE], uint8_t, uint8_t);
BOOLEAN collisionCheck(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);

// Main loop
void main() {
    add_VBL(CBTFX_update);  // Audio driver VBL interrupt

    init();  // Call init functions

    while (1) {
        checkInput();        // Check for user input
        spriteMove();        // Call function to move sprites
        bgMove();            // Call function to move background
        asteroidControl();   // Control asteroids creation and movement
        asteroidMove();      // Move asteroids
        astronautControl();  // Control the astronauts
        updateSwitches();    // Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
        wait_vbl_done();     // Wait until VBLANK to avoid corrupting memory
    }
}

// Start sequence. Initiate graphics
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
    set_win_data(idxBkgTiles, idxWinTiles, WinTileSet);
    set_sprite_data(0, idxSprites, Sprites);

    // Set heart palette and tile
    for (uint8_t i = 0; i < numLives; i++) {
        spHeart[i] = spriteCount;
        set_sprite_prop(spHeart[i], 2);  // Heart - Palette 2
        set_sprite_tile(spHeart[i], 15);  // Set tile
        spriteCount++;
    }

    // Set explosion palette
    spExplosion = spriteCount;
    set_sprite_prop(spExplosion, 4);
    spriteCount++;

    // Set asteroids palette
    for (uint8_t i = 0; i < TOTAL_ASTEROIDS; i++) {
        spAsteroid[i] = spriteCount;
        set_sprite_prop(spAsteroid[i], 3);
        spriteCount++;
    }

    // Set world palette and tile
    spWorld = spriteCount;
    set_sprite_prop(spWorld, 1);
    set_sprite_tile(spWorld, 0);
    spriteCount++;

    // Set fire palette
    spFire = spriteCount;
    set_sprite_prop(spFire, 2);
    spriteCount++;

    // Set astronaut var
    spAstronaut = spriteCount;
    spriteCount++;

    // Set astronaut count palette and tile
    spAstronautCount = spriteCount;
    set_sprite_data(idxSprites, 1, charSprites[Numbers[0][numAstronauts] - charOffset]);
    set_sprite_prop(spAstronautCount, 0);
    set_sprite_tile(spAstronautCount, idxSprites);
    spriteCount++;

    // Set astronaut count bg palette and tile
    spCountBg = spriteCount;
    set_sprite_prop(spCountBg, 7);
    set_sprite_tile(spCountBg, idxSprites - 1);    

    DISPLAY_ON;  // Turn on the display

    NR52_REG = 0x8F;  // Turn on the sound
    NR51_REG = 0x11;  // Enable the sound channels
    NR50_REG = 0x77;  // Increase the volume to its max

    // Set logo screen palette and tiles
    setBkgPalette(0, 0, FullWidth, FullHeight, CamardaBoy_a);  // Set bkg palette
    set_bkg_tiles(0, 0, FullWidth, FullHeight, CamardaBoy);    // Set bkg tiles
    move_bkg(0, 0);                                            // Move background to the 0x 0y position

    delay(3500);

    helloPrep();  // Call start screen
}

// Ensures bkg and sprites are visible
void updateSwitches() {
    SHOW_SPRITES;  // Show sprites
    SHOW_BKG;      // Show background
}

// Start screen
void helloPrep() {
    // Set start screen palette and tiles
    setBkgPalette(0, 0, FullWidth, FullHeight, HelloWorld_a);  // Set bkg palette
    set_bkg_tiles(0, 0, FullWidth, FullHeight, HelloWorld);    // Set bkg tiles

    waitpad(J_START);  // Wait for start button press and do initialization

    initrand(DIV_REG);  // Start randon seed

    CBTFX_PLAY_SFX_03;  // Starting effect

    helloStart();  // Call game start sequence
}

// Game start sequence
void helloStart() {
    // Call transition function
    bkgTransition(0);

    // Set universe palette and tiles
    setBkgPalette(0, 0, UniverseWidth, UniverseHeight, Universe_a);
    set_bkg_tiles(0, 0, UniverseWidth, UniverseHeight, Universe);

    do {
        // Show dialog lines
        openDiaLines = showDialog(Start_s1, sizeof(Start_s1) / MAX_STRING_SIZE, openDiaLines);

        // If key is pressed, wait for release
        if (keyDown) {
            waitpadup();
            keyDown = FALSE;
        }

        // Wait for A button press
        waitpad(J_A);
        keyDown = TRUE;

        CBTFX_PLAY_SFX_01;  // Click sound

        performantDelay(5);

    } while (openDiaLines != 0);

    HIDE_WIN;

    // Set world and fire sprite starting location
    world[0] = (DEVICE_SCREEN_PX_WIDTH / 2) + 4;
    world[1] = yMax + 8;
    fire[0] = world[0];
    fire[1] = world[1] + 8;

    set_sprite_tile(spFire, 1);  // Set fire up sprite

    SHOW_SPRITES;

    // Move world to screen center
    for (uint8_t i = 0; i < (DEVICE_SCREEN_PX_HEIGHT / 2); i++) {
        world[1]--;
        fire[1]--;
        move_sprite(spWorld, world[0], world[1]);
        move_sprite(spFire, fire[0], fire[1]);
        delay(30);
    }

    hide_sprite(spFire);  // Hide fire sprite

    performantDelay(10);

    do {
        // Show dialog lines
        openDiaLines = showDialog(Start_s2, sizeof(Start_s2) / MAX_STRING_SIZE, openDiaLines);

        // If key is pressed, wait for release
        if (keyDown) {
            waitpadup();
            keyDown = FALSE;
        }

        // Wait for A button press
        waitpad(J_A);
        keyDown = TRUE;

        CBTFX_PLAY_SFX_01;  // Click sound

        performantDelay(5);

    } while (openDiaLines != 0);

    HIDE_WIN;

    // Put heart sprites on starting location
    aux = 12;
    for (uint8_t i = 0; i < numLives; i++) {
        move_sprite(spHeart[i], aux, 20);
        aux += 10;
    }

    // Place astronaut counter and bg
    move_sprite(spCountBg, xMax, yMin);
    move_sprite(spAstronautCount, xMax, yMin); 
}

// Simple background transitions
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

// Game over sequence
void gameOver() {
    // Do some blinking with the sprites
    for (uint8_t i = 0; i < 6; i++) {
        performantDelay(5);
        HIDE_SPRITES;
        performantDelay(5);
        SHOW_SPRITES;
    }

    // Wait and actually hide sprites
    performantDelay(10);
    hide_sprite(spFire);
    hide_sprite(spWorld);
    hide_sprite(spAstronaut);
    hide_sprite(spAstronautCount);
    hide_sprite(spCountBg);

    for (uint8_t i = 0; i < maxAsteroids; i++) {
        hide_sprite(spAsteroid[i]);
    }

    CBTFX_PLAY_SFX_09;  // Lose sound

    // Show first dialog
    openDiaLines = 0;

    do {
        // Show dialog lines
        openDiaLines = showDialog(GameOver_s1, sizeof(GameOver_s1) / MAX_STRING_SIZE, openDiaLines);

        // If key is pressed, wait for release
        if (keyDown) {
            waitpadup();
            keyDown = FALSE;
        }

        // Wait for A button press
        waitpad(J_A);
        keyDown = TRUE;

        CBTFX_PLAY_SFX_01;  // Click sound

        performantDelay(5);

    } while (openDiaLines != 0);

    HIDE_WIN;

    performantDelay(10);
    move_bkg(0, 0);    // Move background to the 0x 0y position
    bkgTransition(1);  // Call transition function

    // Reset control variables
    resetVariables();

    CBTFX_PLAY_SFX_09;  // Lose sound

    // Set game over screen
    setBkgPalette(0, 0, FullWidth, FullHeight, HelloWorld_a);
    set_bkg_tiles(0, 0, FullWidth, FullHeight, GameOver);

    // Show second dialog
    openDiaLines = 0;

    do {
        // Show dialog lines
        openDiaLines = showDialog(GameOver_s2, sizeof(GameOver_s2) / MAX_STRING_SIZE, openDiaLines);

        // If key is pressed, wait for release
        if (keyDown) {
            waitpadup();
            keyDown = FALSE;
        }

        if (openDiaLines != 0) {  // Wait for A button press
            waitpad(J_A);
            keyDown = TRUE;

            CBTFX_PLAY_SFX_01;  // Click sound

        } else {
            waitpad(J_START);  // Wait for start button press
            keyDown = TRUE;
        }

        performantDelay(5);

    } while (openDiaLines != 0);

    HIDE_WIN;

    // Call start screen
    performantDelay(10);
    CBTFX_PLAY_SFX_03;
    helloPrep();
}

void gameWin() {
    // Increase number of asteroids for next run
    if (maxAsteroids < TOTAL_ASTEROIDS) {
        maxAsteroids++;
    }

    // Increase number of astronauts for next run
    if (maxAstronauts < TOTAL_ASTRONAUTS) {
        maxAstronauts++;
    }

    // Do some blinking with the sprites
    for (uint8_t i = 0; i < 6; i++) {
        performantDelay(5);
        HIDE_SPRITES;
        performantDelay(5);
        SHOW_SPRITES;
    }

    // Wait and actually hide sprites
    performantDelay(10);
    hide_sprite(spFire);
    hide_sprite(spWorld);
    hide_sprite(spAstronaut);
    hide_sprite(spAstronautCount);
    hide_sprite(spCountBg);

    for (uint8_t i = 0; i < maxAsteroids; i++) {
        hide_sprite(spAsteroid[i]);
    }

    for (uint8_t i = 0; i < numLives; i++) {
        hide_sprite(spHeart[i]);
    }

    performantDelay(10);
    CBTFX_PLAY_SFX_07;  // Sound effect

    performantDelay(10);
    move_bkg(0, 0);    // Move background to the 0x 0y position
    bkgTransition(1);  // Call transition function

    // Reset control variables
    resetVariables();

    // Call start screen
    performantDelay(10);
    CBTFX_PLAY_SFX_03;
    helloPrep();
}

// Checks for gamepad input and act on it
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

// Move player sprite
void spriteMove() {
    // Move the sprite to the position of X and Y
    move_sprite(spWorld, world[0], world[1]);

    if (hideFire) {
        hide_sprite(spFire);
    } else {
        move_sprite(spFire, fire[0], fire[1]);
    }

    // If there is a colision between the player and the astronaut
    collision = collisionCheck(world[0], world[1], 8, 8, astronaut[0], astronaut[1], 4, 4);

    if (collision) {
        resetAstronaut = TRUE;
        numAstronauts++;

        CBTFX_PLAY_SFX_02;  // Sound effect

        // Update counter sprite
        set_sprite_data(idxSprites, 1, charSprites[Numbers[0][numAstronauts] - charOffset]);
        set_sprite_tile(spAstronautCount, idxSprites);

        // Got all astronauts, win game
        if (numAstronauts == maxAstronauts) {
            resetAstronaut = FALSE;
            gameWin();
        }
    }
}

// Control asteroids
void asteroidControl() {
    if (startAsteroid) {
        if (numAsteroids < maxAsteroids || resetAsteroid) {
            // Generate randon numbers
            randNum = rand();
            randNum2 = rand();

            // If asteroid is a new one (not destroyed)
            if (!resetAsteroid) {
                currAsteroid = numAsteroids;
            }

            // Define screen side for asteroid start
            // propAsteroid[0] indicates the screen side
            if (randNum < 64) {  // Asteroid comes from up
                asteroids[0][currAsteroid] = (randNum2 * DEVICE_SCREEN_PX_WIDTH) / 255;
                asteroids[1][currAsteroid] = 0;
                propAsteroid[0][currAsteroid] = 0;

            } else if (randNum < 128) {  // Asteroid comes from bottom
                asteroids[0][currAsteroid] = (randNum2 * DEVICE_SCREEN_PX_WIDTH) / 255;
                asteroids[1][currAsteroid] = DEVICE_SCREEN_PX_HEIGHT;
                propAsteroid[0][currAsteroid] = 1;

            } else if (randNum < 192) {  // Asteroid comes from left
                asteroids[0][currAsteroid] = 0;
                asteroids[1][currAsteroid] = (randNum2 * DEVICE_SCREEN_PX_HEIGHT) / 255;
                propAsteroid[0][currAsteroid] = 2;

            } else {  // Asteroid comes from right
                asteroids[0][currAsteroid] = DEVICE_SCREEN_PX_WIDTH;
                asteroids[1][currAsteroid] = (randNum2 * DEVICE_SCREEN_PX_HEIGHT) / 255;
                propAsteroid[0][currAsteroid] = 3;
            }

            randNum = rand();

            // Define sprite variant
            // propAsteroid[1] indicates the asteroid direction/angle
            if (randNum < 85) {
                propAsteroid[1][currAsteroid] = 0;  // Sprite 1 - Left OR Up
            } else if (randNum < 170) {
                propAsteroid[1][currAsteroid] = 1;  // Sprite 2 - Right OR Down
            } else {
                propAsteroid[1][currAsteroid] = 2;  // Sprite 3 - Center
            }

            // propAsteroid[2] indicates the asteroid tile to use
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

            set_sprite_tile(spAsteroid[currAsteroid], propAsteroid[2][currAsteroid]);  // Set asteroid sprite

            if (resetAsteroid) {
                resetAsteroid = FALSE;
            } else {
                numAsteroids++;
            }

            startAsteroid = FALSE;
        }
    }

    timeAsteroid++;

    randNum = rand();

    // Create a new asteroid
    if ((timeAsteroid > 300 + randNum) && (numAsteroids < maxAsteroids)) {
        startAsteroid = TRUE;
        timeAsteroid = 0;
    }
}

// Move the asteroids
// TO-DO: Add velocity control?
void asteroidMove() {
    for (uint8_t i = 0; i < numAsteroids; i++) {
        move_sprite(spAsteroid[i], asteroids[0][i], asteroids[1][i]);

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
            if (randNum < 15 || randNum > 240) {
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
        if (!stopBG && corrBgMove) {
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

void astronautControl() {
    if (numAstronauts < maxAstronauts) {
        if (resetAstronaut) {
            resetAstronaut = FALSE;

            do {
                randNum = rand();
                randNum2 = rand();

                // Determine astronaut X and Y position
                astronaut[0] = (randNum * uniPxWidth) / 255;
                astronaut[1] = (randNum2 * uniPxHeight) / 255;

                // Check if astronaut is not on player location
                collision = collisionCheck(world[0], world[1], 8, 8, astronaut[0], astronaut[1], 8, 8);

            } while (collision);

            initrand(DIV_REG);

            randNum = rand();
            randNum2 = rand();

            // Determines astronaut tile
            if (randNum < 50 || randNum > 200) {
                set_sprite_tile(spAstronaut, 16);
            } else {
                set_sprite_tile(spAstronaut, 17);
            }

            // Determines astronaut palette
            if (randNum2 < 20 || randNum2 > 170) {
                set_sprite_prop(spAstronaut, 5);
            } else {
                set_sprite_prop(spAstronaut, 6);
            }

            // Put astronaut on position
            move_sprite(spAstronaut, astronaut[0], astronaut[1]);
        }

        // Corrections to compensate background movement
        if (!stopBG && corrBgMove) {
            switch (bgMoveDir) {
                case 0:  // Background moving to the left
                    astronaut[0]--;
                    break;
                case 1:  // Background moving to the right
                    astronaut[0]++;
                    break;
                case 2:  // Background moving to the top
                    astronaut[1]--;
                    break;
                case 3:  // Background moving to the bottom
                    astronaut[1]++;
                    break;
                default:
                    break;
            }
        }

        // Put astronaut on position
        move_sprite(spAstronaut, astronaut[0], astronaut[1]);
    }
}

// Moves the background
void bgMove() {
    // Move the background if the player is on the edge of the map
    if (!stopBG) {
        if ((world[0] >= xMax) && xMove) {  // Right limit of screen, move bkg left
            scroll_bkg(1, 0);
            bgMoveDir = 0;
            corrBgMove = TRUE;

        } else if ((world[0] <= xMin) && xMove) {  // Left limit of screen, move bkg right
            scroll_bkg(-1, 0);
            bgMoveDir = 1;
            corrBgMove = TRUE;

        } else if ((world[1] >= yMax) && !xMove) {  // Bottom limit of screen, move bkg up
            scroll_bkg(0, 1);
            bgMoveDir = 2;
            corrBgMove = TRUE;

        } else if ((world[1] <= yMin) && !xMove) {  // Top limit of screen, move bkg down
            scroll_bkg(0, -1);
            bgMoveDir = 3;
            corrBgMove = TRUE;

        } else {
            corrBgMove = FALSE;
        }
    }
}

// Simple explosion animation
void explosion() {
    // Hide the asteroid
    delay(10);
    hide_sprite(spAsteroid[currAsteroid]);

    CBTFX_PLAY_SFX_05;  // Explosion sound

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

// Remove lives when the player hits a asteroid
void removeLives() {
    numLives--;

    hide_sprite(spHeart[numLives]);  // Hide heart sprite

    if (numLives == 0) {
        performantDelay(5);
        gameOver();
    }
}

// Set need variables back to starting values
void resetVariables() {
    numLives = TOTAL_LIVES;
    numAsteroids = 0;
    timeAsteroid = 0;
    numAstronauts = 0;
    aux = 0;

    // Reset astronaut sprite
    set_sprite_data(idxSprites, 1, charSprites[Numbers[0][numAstronauts] - charOffset]);
    set_sprite_tile(spAstronautCount, idxSprites);
}

// Set palette for the background
void setBkgPalette(uint8_t xMin, uint8_t yMin, uint8_t xMax, uint8_t yMax, unsigned char map[]) {
    VBK_REG = VBK_ATTRIBUTES;                    // Select VRAM bank 1
    set_bkg_tiles(xMin, yMin, xMax, yMax, map);  // Set bkg atributes
    VBK_REG = VBK_TILES;                         // Swittch back to VRAM bank 0
}

// Simple replacement for wait()
void performantDelay(uint8_t numloops) {
    for (uint8_t i = 0; i != numloops; i++) {
        wait_vbl_done();
    }
}

// Draws given text in the dialog box
uint8_t showDialog(unsigned char textLines[][MAX_STRING_SIZE], uint8_t numLines, uint8_t lastLine) {
    set_win_data(blackTileAdr, 1, blackTile);

    // Clear window with black tiles
    for (uint8_t i = 0; i != charOffset; i++) {
        set_win_data(firstRowAdr + i, 1, blackTile);
    }

    // Write the next two lines
    for (aux = 0; aux != 2; aux++) {
        for (uint8_t i = 0; i < 16; i++) {
            if (aux == 0) {
                set_win_data(firstRowAdr + i, 1, charSprites[textLines[aux + lastLine][i] - charOffset]);  // First line
            } else {
                set_win_data(secondRowAdr + i, 1, charSprites[textLines[aux + lastLine][i] - charOffset]);  // Second line
            }
        }

        // When amount of lines is even
        if ((aux + 1) + lastLine == numLines) {
            return 0;
        }

        // When amount of lines is odd
        if (aux + lastLine == numLines) {
            // remove second, black line
            for (uint8_t i = 0; i != 16; i++) {
                set_win_data(secondRowAdr + i, 1, DiaWindow);
            }
            return 0;
        }
    }

    set_win_tiles(0, 0, 20, 5, DiaWindow);
    move_win(7, 104);

    SHOW_WIN;

    return aux + lastLine;
}

// Checks collision between two objects
BOOLEAN collisionCheck(uint8_t x1, uint8_t y1, uint8_t w1, uint8_t h1, uint8_t x2, uint8_t y2, uint8_t w2, uint8_t h2) {
    if ((x1 < (x2 + w2)) && ((x1 + w1) > x2) && (y1 < (h2 + y2)) && ((y1 + h1) > y2)) {
        return TRUE;
    } else {
        return FALSE;
    }
}