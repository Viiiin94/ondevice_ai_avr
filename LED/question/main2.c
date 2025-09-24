#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

int main()
{
    LED_DDR = 0xff;
    while (1)
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            LED_PORT = (0b00010000 << i) | (0b00001000 >> i);
            _delay_ms(300);
        }
        for (uint8_t i = 0; i < 3; i++)
        {
            LED_PORT = (0b01000000 >> i) | (0b00000010 << i);
            if (i == 2)
            {
                _delay_ms(0);
                break;
            }
            _delay_ms(300);
        }
    }
}
