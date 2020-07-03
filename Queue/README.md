이 프로그램은 Queue에 큐의크기와 원소 수를 반환하는 기능을한다.

크게 나누면 main과 class Queue 으로 나눌 수 있는데, 

먼저 class Queue는 큐의 배열과 크기와 원소수를 반환하는 핵심 함수이다.

<h3>private</h3> 

큐의 배열인 arr와 큐의 위치인 fornt,rear 그리고 크기를 의미하는 capacity가 있다.

<h3>public</h3>

* 생성자: Queue()

* 삽입함수: push(T tdata)

* 삭제함수: pop()

* 크기와 원소수를 알려주는 함수: void size()

main 에서는 queue를 정의한다음 삽입 했을때와 삭제했을때의 크기와 원소수를 출력한다.

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.
