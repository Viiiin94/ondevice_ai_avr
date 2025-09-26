#include "ap.h"

void apInit()
{
}

void apMain()
{
    UART0_Init();

    DDRD = 0xff;

    FND_DATA_DDRA = 0xff;
    FND_DATA_DDRB = 0xff;

    FND_SELECT_DDR = 0xff;
    FND_SELECT_PORT = 0x00;

    char data;

    while (1)
    {
        data = UART0_Receive();
        UART_Transmit(data);

        if (data == 'a')
        {
            PORTD = 0xff;
            _delay_ms(300);
        }
        else
        {
            _delay_ms(50);
            FND_Display(data);
        }
    }
}
