#include "./src/ap/ap.h"

int main()
{
    // apInit();
    // apMain();

    DDRB |= (1 << PB4);

    // pwm , 논 인버티드 모드, 256 분주
    TCCR0 |= (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS02) | (1 << CS01);

    while (1)
    {
        for (uint8_t i = 0; i < 255; i++)
        {
            OCR0 = i;

            _delay_ms(10);
        }
    }
}
