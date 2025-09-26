#include "./common/def.h"

#define FND_DATA_DDRA DDRA
#define FND_DATA_PORTA PORTA

#define FND_DATA_DDRB DDRB
#define FND_DATA_PORTB PORTB
#define FND_SELECT_DDR DDRC
#define FND_SELECT_PORT PORTC

void FND_Display(uint8_t data); // 8bit 를 넘어가기때문에 16bit 사용함
