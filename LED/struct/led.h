#include "../common/def.h"

#define LED_DDR DDRD
#define LED_PORT PORTD

// LED 구조체 정의
typedef struct
{
    volatile uint8_t *port;     // volatile => 컴파일시 최적화 하지 마시오!
    uint8_t pinNumber;
} LED;

void ledInit(LED *led);
void ledOn(LED *led);
void ledOff(LED *led);
void ledLeftShift(LED *led);
