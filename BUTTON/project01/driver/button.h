#include "../common/def.h"

#define LED_DDR DDRD
#define LED_PORT PORTD
#define BUTTON_DDR DDRG
#define BUTTON_PIN PING
#define BUTTON_ON 0
#define BUTTON_OFF 1
#define BUTTON_TOGGLE 2

enum
{
    PUSHED,
    RELEASED
};
enum
{
    NO_ACT,
    ACT_PUSH,
    ACT_RELEASE
};

typedef struct
{
    volatile uint8_t *ddr;
    volatile uint8_t *pin;
    uint8_t btnPin;
    uint8_t prevState; // 이전상태
} BUTTON;

void buttonInit(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t buttonGetState(BUTTON *button);
