// 깜빡깜빡
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // PORT D DATA DIRECTION Register
    // (DDRD)방향레지스터를 통해서 PORTD를 출력으로 설정
    DDRD = 0b11111111; // 2진수, 방향레지스터 1을 쓰면 출력
    //  DDRD = 0xFF; 16진수

    while (1)
    {
        PORTD = 0xff;   // 출력이니까.. 전압(전류)을 내보내 !
        _delay_ms(500); // 500ms 지연 !!
        PORTD = 0x00;   // 출력이지만.. 전압(전류)을 보내지마 !
        _delay_ms(500); // 500ms 지연 !!
    }
}
