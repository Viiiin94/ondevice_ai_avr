#include "ap.h"

void apInit()
{
}

void apMain()
{

    stdout = &OUTPUT;

    UART_Init();
    sei();

    while (1)
    {
        if (rxFlag == 1)
        {
            rxFlag = 0;
            printf(rxBuff);
        }
    }
}
