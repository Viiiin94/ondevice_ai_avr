#include "ap.h"

void apInit()
{
}

void apMain()
{
    FND_DATA_DDR = 0xff;
    FND_SELECT_DDR = 0xff;

    FND_SELECT_PORT = 0x00;

    uint16_t count = 0;
    uint32_t timeTick = 0;
    uint32_t prevTime = 0;

    while (1)
    {    
        // count 9999넘으면 0으로 초기화
        if(count > 9999)
        {
            count = 0;
        }
        
        FND_Display(count); // FND에 count 값을 출력

        if (timeTick - prevTime > 100) // 100ms 지날 때마다 count 값을 1씩 증가
        {
            prevTime = timeTick;
            count++;
        }
        _delay_ms(1);
        timeTick++;
    }
}
