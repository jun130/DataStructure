#include <iostream>
using namespace std;
template <class T>

class Queue{
private:
	T *arr; // queue의 array
	int front, rear, capacity; 
public:
	Queue() { // queue의 초기화 생성자
		capacity = 10; // queue 크기를 초기화
		arr = new T[10];  // 실제 저장배열에 메모리 할당
		front = 0; 
		rear = 0;
	}
	void push(T tdata) {
		/*
		if (rear + 1 == capacity) {
			arr + 10 = new T[10];
			rear = rear + 10;
			capacity = capacity + 10;
		}
		*/
		*(arr+rear) = tdata;
		rear = (rear + 1) % capacity; // 원형큐 구현
	}
	void pop() {
		*(arr + front) = -1; // pop 표시
		front = (front + 1) % capacity; 
	}
	void size() { // queue 크기와 원소수를 반환하는 함수
		cout << "큐의 크기 : " << capacity << "\n";
		if (rear > front) {  // rear이 한바퀴 돌지 않았을 경우
			cout << "큐의 원소수 : " << rear - front << "\n";
		}
		else { // rear이 한바퀴 돌앗을 경우
			cout << "큐의 원소수 : " << capacity + rear - front << "\n"; 
		}
		
	}
};

int main() {
	Queue<int> queue;
	for (int i = 0; i < 10; i++) {
		queue.push(i);
	}
	queue.size();
	for (int j = 0; j < 5; j++) {
		queue.pop();
	}
	queue.size();

	
return 0;
}
