이 프로그램은 x,y 두개의 오름차순된 체인을 z라는 체인으로 합병할때도 오름차순 정렬시키는 기능을한다.
크게 나누면 main과 class chain, class chain_node,  merger 으로 나눌 수 있는데, 
먼저 chain_node는 체인의 노드에 대해 정의한 class이다.
private 에 data와 다음노드를 가리키는 포인터 next가 있다.
public 은 
생성자: chain_node()
삽입함수: chain_node *insert(int curr_data, chain_node *tail) 가 있다.

다음으로 체인을 정의한 class chain 을 살펴보면
private 에 head와 tail 이 존재하며
public 은 
생성자: chain()
get, tail 함수 존재
setnull() :  공백리스트 구분하는 함수

체인을 합병하는 함수인 merger 은 각각의 체인의 head 링크를 가져와 합병하는 동안 
각 노드의 tail에 도달여부를 조건문을 통해 확인하고 다 합병된 경우 사용한 체인을 공백리스트로 만들기위해 
setnull을 사용한다.

main 에서는 각각의 체인을 정의하고 합병되기 전 후로 오름차순을 출력한다.

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.
시간복잡도 : O(n^2) n은 x,y 체인 노드의 개수.
