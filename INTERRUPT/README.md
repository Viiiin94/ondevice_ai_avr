# atmega128a

## Interrupts

- 인터럽트는 하드웨어(타이머 오버플로우, 외부 핀 변화, UART 수신 등)가 **즉시 처리되어야 하는 이벤트**를 CPU에게 알리는 메커니즘입니다. CPU는 현재 작업을 잠깐 멈추고 미리 정해진 **ISR(Interrupt Service Routine)** 로 점프해 필요한 처리를 한 뒤 `RETI`로 복귀합니다.

### ISR(Interrupt Service Reactive)함수

- 그간 코드에 있는 함수를 실행
- 인터럽트가 들어오면 하던 일을 멈추고 ISR 함수가 실행됨
- 인터럽트가 되고 다시 돌아올 때 위치를 기억해야하니깐 SP(Stack Pointer)에 위치를 저장하고 그 다음부터 다시 실행(Context Switching)이 됨

![Screenshot from 2025-09-25 11-35-15.png](attachment:030cfbcb-ede5-442b-9cfa-9f5abaa57428:Screenshot_from_2025-09-25_11-35-15.png)

### INTERRUPT

- INT0 ~ INT7의 트리거 방식(저레벨/변화/하강/상승) 설정.
- 2개씩 묶여있음 high(1), low(0)로 총 4가지 조합을 만들 수 있음
- EICRA와 다르게 EICRB는 0 1 일 때 동작이 다름 다름

- EICRA
    - INT0 ~ INT3

![Screenshot from 2025-09-25 11-37-33.png](attachment:f58e314f-2181-4b8f-a4cf-f31d43b31f93:Screenshot_from_2025-09-25_11-37-33.png)

![Screenshot from 2025-09-25 11-41-42.png](attachment:c429b064-7c32-42bd-a500-39196e90ddb8:Screenshot_from_2025-09-25_11-41-42.png)

- EICRB
    - INT4 ~ INT7

![Screenshot from 2025-09-25 11-45-20.png](attachment:181fb532-f1ff-4c5a-86ec-59781bcb93b6:Screenshot_from_2025-09-25_11-45-20.png)

![Screenshot from 2025-09-25 11-48-23.png](attachment:08ee86a4-60f3-4b09-bea5-6ff0449a0fc1:Screenshot_from_2025-09-25_11-48-23.png)

### SREG

- SREG
    - Enable 시키려면 set 해야함
    - INT0 ~ INT7 개별 허용 비트.
    - 그리고 Global interrupt는 무조건 연결이 되어야한다.
    - 현재 우리는 I, T 번 핀(7, 6)에 연결

![Screenshot from 2025-09-25 11-53-34.png](attachment:a389e589-62f9-49ca-a760-68ac094cf0a3:Screenshot_from_2025-09-25_11-53-34.png)

### EIMSK

- 마찬가지로 Enable 시키려면 set 해야함

![Screenshot from 2025-09-25 11-54-26.png](attachment:cccf7567-2641-4be1-acea-1208caad94f2:Screenshot_from_2025-09-25_11-54-26.png)

### EIFR

- INTFx 플래그(트리거 됐는지).
- 트리거 되면 1이됨
- ISR이 실행되면 0으로 되고 또 다른 방법은 코드 상 FLAG = 1하면 0으로 바뀜

![Screenshot from 2025-09-25 12-19-03.png](attachment:4d6445fb-d8b6-47c9-a6b2-43e936842895:Screenshot_from_2025-09-25_12-19-03.png)
