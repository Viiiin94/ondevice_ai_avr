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
			      // + 나 or이나 똑같이 반응함
            LED_PORT |= (0b00010000 << i) + (0b00001000 >> i);
            _delay_ms(300);
        }
        for (uint8_t i = 0; i < 4; i++)
        {
            LED_PORT ^= (0b10000000 >> i) + (0b00000001 << i);
            _delay_ms(300);
        }
        
        // 교수님 방법 (참고)
        for (uint8_t i = 7; i >= 4; i--)
        {
            LED_PORT &= ~((0x01 << i) | (0x80 >> i));
            _delay_ms(300);
        }
    }
}
