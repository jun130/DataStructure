이 프로그램은 중위 표기식을 전위 표기식으로 변환시키는 기능을한다.
크게 나누면 main과 class in_to_pre 으로 나눌 수 있는데, 
먼저 main으로 부터 중위표기식을 받는 class in_to_pre 부터 살펴보면
private 에는 중위표기식의 문자를 저장하는 토큰 atok와 연산자를 저장하는 btok가 있고,

public 은 
void convert(char *infix) : 중위표기식을 전위표기식으로 변환하는 함수가 btok에 쌓이는 스택에 따라 다른작동을 하도록 설계했다. 

main 에서는 30자 이내의 중위표기식을 입력받고 30자이내로 입력하지않을 경우 try-catch 예외처리 하였다. 함수 convert를 통해 변환.  

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.

