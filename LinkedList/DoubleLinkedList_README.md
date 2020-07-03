이 프로그램은 헤더 노드를 가진 이중 원형 연결리스트를 C++ templete class 로 구현 하였다.
크게 나누면 main과 class cd_list 로 나눌 수 있는데, 
먼저 cd_list 부터 살펴보면 prviate에 data와 좌우 데이타를 가리키는 링크인 lnext rnetx 가 선언 되었다. 
그다음 public에는 생성자, 복사생성자, 파괴자, 삽입함수 ,삭제함수가 존재한다. 이를 정의하면..
생성자 : cd_list()
복사생성자 : cd_list(const cd_list &c) 
파괴자 : ~cd_list(){}
삽입함수 : 
cd_list<T> *finsert : front에서 부터 입력하는 함수이다.   
cd_list<T> *rinsert : rear에서 부터 입력하는 함수이다.
삭제함수 :
cd_list<T> *ndelete(T cdata) :  

그 외 출력함수 : 
ostream& operator<<(ostream &os, cd_list<int> *node) : 노드 헤드를 입력받아 출력하는함수

세부적인 함수의 동작설명은 cpp파일에 주석으로 처리함.
