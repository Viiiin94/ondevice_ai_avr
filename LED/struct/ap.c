#include "ap.h"

void apInit()
{
}

void apMain()
{
    LED led;

    led.port = &PORTD; // PORTD의 주소값은 0x12 (데이터시트 참조)
    led.pinNumber = 0; // 그냥 핀 번호임

    // ledInit(&led); // ledInit 함수를 호출하면서 led변수의 주소를 보냄

    while (1)
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            led.pinNumber = i;
            ledInit(&led);
            ledLeftShift(&led);
            _delay_ms(400);
        }
    }
}
