#include "uart0.h"

/**
 * @brief UART
 * 통신속도 9600bps
 * 비동기모드, 2배속, 8비트 데이터, 패리티비트 없음, 스톱비트 1개
 *
 */

void UART0_Init()
{
    // 일단 통신속도
    UBRR0H = 0x00;
    UBRR0L = 207; // 0xCF;

    // 2배속 모드
    UCSR0A |= (1 << U2X0);

    // 송, 수신 활성화
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // 비동기, 패리티 없음, 스톱 비트 1개, 데이터 비트 8비트
    // UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 이 세팅 값이 default 값 !!
}
void UART_Transmit(char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ; // 송신 가능 ??? UDR이 비어있는지???
    UDR0 = data;
}
unsigned UART0_Receive()
{
    while (!(UCSR0A & (1 << RXC0)))
        ; // 데이터 수신 대기
    return UDR0;
}
