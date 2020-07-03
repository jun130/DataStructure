이 프로그램은 전위 표기식을 계산하는 기능을한다.
크게 나누면 main과 class prefix 으로 나눌 수 있는데, 
먼저 전위표기식을 받고 계산하는 class prefix 부터 살펴보면
private 에 main에서 입력한 전위표기식을 받아 저장하는 int형 배열 token이 있고,

public 은 
생성자: Prefix()
계산하는 함수: int calcul(char *str) 이 있다.

main 에서는 전위표기식을 입력받는다. 계산하는함수 calcul을 이용해 값을 출력한다.

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.

