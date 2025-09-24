// 복합연산자와 shift를 활용한 0~7까지 하나씩 중첩으로 켜짐
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
        for (uint8_t i = 0; i < 8; i++) // 8bit unsigned int / 0 -> 7
        {
            LED_PORT |= (1 << i); // LED_PORT = LEDPORT | (1 << i);
            _delay_ms(200);
        }
        LED_PORT = 0x00;
        _delay_ms(200);
        for (int8_t i = 7; i >= 0; i--) // 8bit int / 7 -> 0
        {
            LED_PORT |= (1 << i); // LED_PORT = LEDPORT | (1 << i);
            _delay_ms(200);
        }
        LED_PORT = 0x00;
        _delay_ms(200);
    }
}
