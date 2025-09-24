#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

uint8_t ledArr[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81};

int main()
{
    LED_DDR = 0xff;

    while (1)
    {
        for (uint8_t i = 0; i < 7; i++)
        {
            LED_PORT = ledArr[i];
            _delay_ms(200);
        }
    }
}
