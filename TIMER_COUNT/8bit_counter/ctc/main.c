#include "./src/ap/ap.h"

int main()
{
    // DDRB = 0xff;        //PB 를 출력으로 설정
    DDRB |= (1 << PB4); // PB4 만 출력으로 쓰겠다

    // TCCR0 = 0x1C;       //0001 1100
    // CS00=1, CS02=1 ==> 128
    // CS01,02 1로 하면 256
    // 분주비
    // TCCR0 |= (1<<COM00) | (1<<WGM01) | (1<<CS02); // 64
    TCCR0 |= (1 << COM00) | (1 << WGM01) | (1 << CS02) | (1 << CS00); // 128
    // TCCR0 |= (1 << COM00) | (1 << WGM01) | (1 << CS02) | (1 << CS01); // 256

    OCR0 = 124;

    while (1)
    {
        while ((TIFR & 0x02) == 0)
            ; // OCF0 가 1이 될때까지 반복(flag 가 설때까지)
        TIFR = 0x02;
        OCR0 = 124;
    }
}
