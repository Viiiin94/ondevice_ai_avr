// 홀짝홀짝
#define LED_DDR DDRD
#define LED_PORT PORTD

int main()
{
    LED_DDR = 0xff;
    while (1)
    {
        LED_PORT = 0x55; // 홀 0b01010101
        _delay_ms(500);
        LED_PORT = 0xAA; // 짝 0b10101010
        _delay_ms(500);
    }
}
