#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

void ledInit() // LED 초기화 함수
{
    DDRD = 0xff;
}

void ledOn() // LED ON 함수
{
    PORTD = 0xff;
}

void ledOff() // LED OFF 함수
{
    PORTD = 0x00;
}

void ledRightShift()
{
    PORTD >>= 1;
}

void ledLeftShift()
{
    PORTD <<= 1;
}

int main()
{
    ledInit();

    while (1)
    {
        ledOn();
        _delay_ms(500);

        ledOff();
        _delay_ms(500);
    }
}
