#include <iostream>

using namespace std;

class chain;             
int merger(chain &x, chain &y, chain &z); // 체인합병함수 프로토타입 선언
class chain_node
{
private:
	int data;
	chain_node *next;

public:
	chain_node() { data = NULL, next = NULL; }
	chain_node *rearinsert(int curr_data, chain_node *tail) { // 기존의 연결리스트 insert함수는 head에 초기값을 넣은반해 
		                                                      // 원형 리스트의경우는 head->next에 초기값을 입력

		if (this->next != tail) {  // front insert를 먼저 사용 할 경우의 초기화 
			                       // why? front insert를 먼저 사용 할경우 초기 node의 next는 tail이 아니라 front insert 의 값
			chain_node *temp = new chain_node;
			this->next = temp; 
			temp->data = curr_data;
			temp->next = tail;

			return temp;
		}
		else {                   // front insert를 먼저 사용 안할 경우의 초기화
			chain_node *temp = new chain_node;
			temp->next = tail;

			temp->data = curr_data;
			temp->next = tail;
			this->next = temp;

			return temp;
		}
	}
	chain_node *frontinsert(int curr_data, chain_node *tail, chain_node *head) { // 앞에서부터 입력이되는 함수

		if (tail->next != head) {   // 노드의 끝 다음이 노드의 헤드를 가르키지 않을 경우 (최초의 경우)
			
			
			chain_node *temp = new chain_node;
			temp->data = curr_data;
			if (head->next != NULL) {
				chain_node *temp2 = head->next;
				head->next = temp;
				temp->next = temp2;
				tail->next = head;
			}
			else {
				head->next = temp;
				temp->next = tail;
				tail->next = head;
			}
			return temp;
		}
		else { // 노드 헤드의 앞에 인설트한다.
			chain_node *temp = new chain_node;
			temp->data = curr_data;
			temp->next = this;
			head->next = temp;
			return temp;
		}
		
	}
	friend int merger(chain &x, chain &y, chain &z);
	int getdata() const {
		return data;
	}

	friend ostream &operator<<(ostream &os, chain &c);
	friend class chain;
};

class chain
{

private:
	chain_node *head;
	chain_node *tail;
public:
	chain() {
		head = new chain_node;
		tail = new chain_node;
	}
	chain_node *gethead() const {

		return head;
	}
	chain_node *gettail() const {

		return tail;
	}
	void setnull() {
		head = NULL;
		delete tail;
	}

	friend ostream &operator<<(ostream &os, chain &c);


};



int main() {
	chain x, y, z;
	chain_node *x_curr, *x_head, *y_curr, *y_head;
	x_curr = x.gethead();
	
	
	y_curr = y.gethead();

	for (int i = 0; i < 5; i++) {
		y_curr = y_curr->rearinsert(i, y.gettail());
	}

	for (int i = 5; i < 10; i++) {
		x_curr = x_curr->frontinsert(15-i, x.gettail(), x.gethead()); // 오름차순으로 초기화
	}

	
	cout << "x의 오름차순 :" << x << "\n"; 
	
	cout << "y의 오름차순 :" << y << "\n";

	merger(x, y, z);
	cout << "z의 오름차순 :" << z<< "\n";
	cout << "x의 오름차순 :" << x << "\n";
	cout << "y의 오름차순 :" << y << "\n";

	return 0;
}

ostream &operator<<(ostream &os, chain &c) {
	chain_node *x = c.gethead();
	
	if (x == NULL) {
		os << "공백리스트입니다";
		return os;
	}
	x = x->next; // head->next부터 값이 유효하므로
	while (x != c.gettail()) {
		os << x->data;
		os << "-";
		x = x->next;
	}


	return os;
}

int merger(chain &x, chain &y, chain &z) { 
	chain_node *x_n = x.gethead();

	x_n = x_n->next;
	chain_node *y_n = y.gethead();
	
	y_n = y_n->next;
	chain_node *z_n = z.gethead();
	
	chain_node *pre_x, *pre_y;
	




	while ((x_n != x.gettail()) && (y_n != y.gettail())) {
		if (x_n->getdata() < y_n->getdata()) {
			z_n = z_n->rearinsert(x_n->getdata(), z.gettail());
			pre_x = x_n;
			x_n = x_n->next;
			delete pre_x;
		}
		else if (x_n->getdata() > y_n->getdata()) {
			z_n = z_n->rearinsert(y_n->getdata(), z.gettail());
			pre_y = y_n;
			y_n = y_n->next;
			delete pre_y;

		}
		else {
			z_n = z_n->rearinsert(x_n->getdata(), z.gettail());
			z_n = z_n->rearinsert(y_n->getdata(), z.gettail());
			pre_x = x_n;
			pre_y = y_n;
			x_n = x_n->next;
			y_n = y_n->next;
			delete pre_x;
			delete pre_y;
		}
	}
	while ((x_n == x.gettail()) ^ (y_n == y.gettail())) {
		if (x_n == x.gettail()) {
			z_n = z_n->rearinsert(y_n->getdata(), z.gettail());
			pre_y = y_n;
			y_n = y_n->next;
			delete pre_y;

		}
		else if (y_n == y.gettail()) {
			z_n = z_n->rearinsert(x_n->getdata(), z.gettail());
			pre_x = x_n;
			x_n = x_n->next;
			delete pre_x;

		}
	}
	x.setnull();
	y.setnull();
	return 0;
}
