#include "fnd.h"

void FND_Display(uint8_t data)
{
    uint8_t fndData[10] = {
        0x3f,
        0x06,
        0x5b,
        0x4f,
        0x66,
        0x6d,
        0x7d,
        0x07,
        0x7f,
        0x6f,
    };

    uint8_t index = data - '0';
    FND_DATA_PORTA = fndData[index];
    FND_DATA_PORTB = fndData[index];
}
