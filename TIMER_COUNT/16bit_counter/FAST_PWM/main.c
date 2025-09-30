#include "./src/ap/ap.h"

/**
 * @brief 16비트 타이머/ 카운터 PAST PWM
 *
 * 64분주, 100Hz 주파스 생성
 * 계산결과 -> 2499
 */

int main()
{
    // apInit();
    // apMain();

    DDRB |= (1 << PB5); // pwm 신호가 나감 port 출력 선언

    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
    //  TCCR1C // 초기화 작업 끝 (non pwm에서만 사용)

    ICR1 = 2499;
    OCR1A = 625; // 25%    1250 -> 50%      1875 -> 75% width

    while (1)
    {
        for (uint16_t i = 0; i < 2499; i++)
        {
            OCR1A = i;
            _delay_ms(20);
        }
    }
}
