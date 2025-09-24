#include "button.h"

// BUTTON btnOn -> BUTTON 이라는 데이터 형의 변수 btnOn 선언과 동시에 메모리 확보
// buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON); ->

void buttonInit(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
    button->ddr = ddr;
    button->pin = pin;
    button->btnPin = pinNum;
    button->prevState = RELEASED;           // 아무 것도 안누른 상태
    *button->ddr &= ~(1 << button->btnPin); // 버튼핀을 입력으로 설정
};

// buttonGetState(&btnOn)

uint8_t buttonGetState(BUTTON *button)
{
    uint8_t currState = *button->pin & (1 << button->btnPin); // PING의 값은 풀업 1 / 풀다운 0 으로 결정

    // 버튼을 누르고 있는 상태 ACT_PUSH를 반환 중이라 ap.c에서 실행되지 않음
    // 버튼을 안 누른 상태에서 누르면
    if ((currState == PUSHED) && button->prevState == RELEASED)
    {
        _delay_ms(50);              // debounce code
        button->prevState = PUSHED; // 버튼 상태를 누른 상태로 변환
        return ACT_PUSH;            // 버튼을 눌렀음을 반환
    }
    // 버튼을 누르고 뗀 상태 ACT_RELEASE를 반환 중이라 ap.c에서 실행이 됨
    // 버튼을 누른 상태에서 손을 떼면
    else if ((currState != PUSHED) && button->prevState == PUSHED)
    {
        _delay_ms(50);
        button->prevState = RELEASED; // 버튼 상태를 안 누른 상태로 변환
        return ACT_RELEASE;           // 버튼에서 손을 뗏음을 반환
    }
    return NO_ACT; // 아무 것도 안함
};
