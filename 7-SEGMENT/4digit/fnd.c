#include "fnd.h"

void FND_Display(uint16_t data)
{
    static uint8_t position = 0;
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

    switch (position) // 현재 출력할 자리에 따라서 해당 자리의 FND를 출력
    {
    case 0:
        // 첫 번째 자리 출력을 위해서는 0번핀 LOW / 1, 2, 3 핀은 HIGH
        FND_SELECT_PORT &= ~(1 << 0);                      // digit 1 : ON
        FND_SELECT_PORT |= (1 << 1) | (1 << 2) | (1 << 3); // digit 2, 3, 4 : OFF

        // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
        FND_DATA_PORT = fndData[data / 1000];
        break;
    case 1:
        // 두 번째 자리 출력을 위해서는 1번핀 LOW / 0, 2, 3 핀은 HIGH
        FND_SELECT_PORT &= ~(1 << 1);                      // digit 1 : ON
        FND_SELECT_PORT |= (1 << 0) | (1 << 2) | (1 << 3); // digit 2, 3, 4 : OFF

        // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
        FND_DATA_PORT = fndData[data / 100 % 10];
        break;
    case 2:
        // 세 번째 자리 출력을 위해서는 2번핀 LOW / 0, 1, 3 핀은 HIGH
        FND_SELECT_PORT &= ~(1 << 2);                      // digit 1 : ON
        FND_SELECT_PORT |= (1 << 0) | (1 << 1) | (1 << 3); // digit 2, 3, 4 : OFF

        // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
        FND_DATA_PORT = fndData[data / 10 % 10];
        break;
    case 3:
        // 네 번째 자리 출력을 위해서는 3번핀 LOW / 0, 1, 2 핀은 HIGH
        FND_SELECT_PORT &= ~(1 << 3);                      // digit 1 : ON
        FND_SELECT_PORT |= (1 << 0) | (1 << 1) | (1 << 2); // digit 2, 3, 4 : OFF

        // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
        FND_DATA_PORT = fndData[data % 10];
        break;
    }

    position++;
    position %= 4;
}
