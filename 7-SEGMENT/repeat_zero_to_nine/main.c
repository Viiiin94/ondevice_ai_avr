#include "./src/ap/ap.h"

int main()
{
    // apInit();
    // apMain();

    // FND 연결된 포트
    DDRA = 0xff;

    int8_t fndNumber[] = {
        0x3f, // 0b00111111 => 0 (a b c d e f)
        0x06, // 0b00000110 => 1 (b c)
        0x5b, // 0b01011011 => 2 (a b d e g)
        0x4f, // 0b01001111 => 3 (a b c d g)
        0x66, // 0b01100110 => 4 (b c f g)
        0x6d, // 0b01101101 => 5 (a c d f g)
        0x7d, // 0b01111101 => 6 (a c d e f g)
        0x07, // 0b00000111 => 7 (a b c)
        0x7f, // 0b01111111 => 8 (a b c d e f g)
        0x6f, // 0b01101111 => 9 (a b c d f g)
    };

    int cnt = 0;

    while (1)
    {
        PORTA = fndNumber[cnt];
        cnt = (cnt + 1) % 10;

        _delay_ms(500);
    }
}
