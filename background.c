/*

 BACKGROUND.C

 Background maps source.

*/

#define FullWidth 20
#define FullHeight 18

const unsigned char HelloWorld[] =
    {
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
        0x01, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x02, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x02,
        0x02, 0x01, 0x01, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x02, 0x01, 0x01,
        0x02, 0x02, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x02, 0x01,
        0x02, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x01,
        0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x10, 0x0D,
        0x14, 0x14, 0x17, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x22, 0x17,
        0x1A, 0x14, 0x0C, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03};

const unsigned char BlackScreen[] =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char BlankScreen[] =
    {
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03};

const unsigned char Tran1[] =
    {
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08,
        0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08};

const unsigned char Tran2[] =
    {
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08,
        0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x08};

const unsigned char Tran3[] =
    {
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06,
        0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06};

const unsigned char Tran4[] =
    {
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06,
        0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06};

#define UniverseWidth 32
#define UniverseHeight 32

const unsigned char Universe[] =
    {
        0x00, 0x00, 0x28, 0x00, 0x00, 0x2B, 0x00, 0x24, 0x24, 0x24,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B,
        0x27, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x2B, 0x00,
        0x00, 0x00, 0x2A, 0x2A, 0x2A, 0x00, 0x00, 0x00, 0x2C, 0x2C,
        0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x25, 0x00,
        0x00, 0x27, 0x00, 0x3A, 0x00, 0x00, 0x24, 0x32, 0x00, 0x2B,
        0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x2B, 0x2B, 0x2C,
        0x2B, 0x2C, 0x26, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24,
        0x2A, 0x00, 0x27, 0x2A, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x33,
        0x00, 0x00, 0x00, 0x2B, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x2E,
        0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2D,
        0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27,
        0x00, 0x2F, 0x31, 0x2B, 0x2C, 0x00, 0x00, 0x2C, 0x00, 0x29,
        0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x26,
        0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00,
        0x2C, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x2C,
        0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x2D, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x24, 0x2B, 0x00, 0x00, 0x25, 0x00, 0x2C, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x25, 0x2C, 0x00,
        0x2C, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x25, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00,
        0x00, 0x00, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x24, 0x00,
        0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2C,
        0x2D, 0x00, 0x2D, 0x39, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00,
        0x00, 0x25, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00,
        0x24, 0x00, 0x00, 0x27, 0x00, 0x2D, 0x3C, 0x3E, 0x2B, 0x2A,
        0x00, 0x00, 0x00, 0x00, 0x2B, 0x2D, 0x00, 0x2D, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2A, 0x27, 0x00, 0x00, 0x3D, 0x3F,
        0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x2D, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x24, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x2B,
        0x00, 0x00, 0x24, 0x00, 0x2A, 0x00, 0x2A, 0x00, 0x00, 0x24,
        0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x26, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x2B, 0x00, 0x00, 0x2C,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C,
        0x34, 0x36, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2B, 0x00, 0x24, 0x00, 0x2C, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00,
        0x2C, 0x00, 0x35, 0x37, 0x2B, 0x00, 0x27, 0x29, 0x00, 0x00,
        0x2D, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x2C, 0x2A,
        0x2B, 0x00, 0x40, 0x42, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x2D,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2D, 0x3B, 0x00, 0x24, 0x00, 0x27,
        0x2C, 0x00, 0x24, 0x00, 0x41, 0x43, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2D, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00,
        0x00, 0x00, 0x27, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00,
        0x29, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x00, 0x2B,
        0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x26, 0x2D, 0x00,
        0x00, 0x28, 0x00, 0x00, 0x2C, 0x2A, 0x00, 0x2B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00,
        0x2C, 0x00, 0x32, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x2D, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x26, 0x00, 0x00, 0x2D, 0x00, 0x29, 0x00, 0x00, 0x00, 0x2D,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x26,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A,
        0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x27, 0x27, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00,
        0x00, 0x26, 0x00, 0x2A, 0x00, 0x27, 0x00, 0x00, 0x2A, 0x00,
        0x00, 0x00, 0x2C, 0x00, 0x00, 0x2B, 0x25, 0x2D, 0x2D, 0x00,
        0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
        0x26, 0x26, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x25, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x25, 0x2D,
        0x00, 0x2C, 0x2D, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00,
        0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00,
        0x2C, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
        0x25, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00,
        0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x2B, 0x00, 0x2A,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x28, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x2C, 0x00, 0x24, 0x3A, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x2E, 0x30, 0x00, 0x29,
        0x00, 0x28, 0x00, 0x2C, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x00,
        0x00, 0x2C, 0x2B, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x31,
        0x00, 0x00, 0x00, 0x28, 0x00, 0x2A, 0x24, 0x00, 0x00, 0x00,
        0x00, 0x28, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x00, 0x27, 0x00, 0x00, 0x29, 0x00, 0x00,
        0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x2B, 0x00,
        0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2A, 0x2C,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x2C, 0x2B, 0x00,
        0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00,
        0x00, 0x00, 0x32, 0x00, 0x24, 0x00, 0x00, 0x2A, 0x00, 0x00,
        0x00, 0x2D, 0x00, 0x2C, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00,
        0x00, 0x28, 0x2D, 0x00, 0x33, 0x2C, 0x27, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x2C, 0x00, 0x40, 0x42,
        0x00, 0x27, 0x00, 0x00, 0x2A, 0x24, 0x24, 0x00, 0x00, 0x2A,
        0x3B, 0x27, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x00,
        0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x41, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x24,
        0x24, 0x26, 0x00, 0x00, 0x2C, 0x2C, 0x2A, 0x00, 0x00, 0x00,
        0x27, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x2C, 0x38,
        0x00, 0x2C, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x27, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00};

const unsigned char GameOver[] =
    {
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
        0x00, 0x01, 0x01, 0x01, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
        0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x00, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01,
        0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x02, 0x00, 0x03, 0x03,
        0x03, 0x03, 0x0F, 0x09, 0x15, 0x0D, 0x03, 0x03, 0x00, 0x01,
        0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x00, 0x03, 0x03,
        0x03, 0x03, 0x17, 0x1E, 0x0D, 0x1A, 0x03, 0x03, 0x00, 0x01,
        0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02,
        0x02, 0x01, 0x00, 0x00, 0x02, 0x01, 0x01, 0x00, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
        0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 0x00, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
        0x00, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03};