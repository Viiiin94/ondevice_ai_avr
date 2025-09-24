#include "led.h"

void ledInit(LED *led)
{
    // 예전 방식
    // PORTD = 0xff;

    // 구조체를 정의했기 때문에 아래와 같이 가능!!
    // 우리가 사용할 포트에 대해서 DDR레지스터를 출력으로 설정해야함!;

    // led->port - 1 PORT 주소를 던지면 DDR 주소가 됨.
    // 즉, DDR 주소의 값을 변경
    *(led->port - 1) |= (1 << led->pinNumber);
    // led->pinNumber 이것은 핀 번호를 얘기함.()
};
void ledOn(LED *led)
{
    // 이번에는 포트에 1을 써야 출력이 됨
    // 해당핀에 1을 씀
    *(led->port) |= (1 << led->pinNumber);
};
void ledOff(LED *led)
{
    // 이번에는 포트에 0을 써야 출력이 안됨
    // 해당핀에 0을 씀
    *(led->port) &= ~(1 << led->pinNumber);
};
void ledLeftShift(LED *led)
{
    *(led->port - 1) |= (1 << led->pinNumber);
    *(led->port) = (1 << led->pinNumber);
}
