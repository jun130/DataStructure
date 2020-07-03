#include <iostream>

using namespace std;

class chain; // chain_node에서 chain을 참조할수있도록 프로토 타입 선언
int merger(chain &x, chain &y, chain &z); // 체인합병함수 프로토타입 선언
class chain_node 
{
private:
	int data;
	chain_node *next;
	
public:
	chain_node() { data = 0, next = NULL; }
	chain_node *insert(int curr_data, chain_node *tail) { // 뒤에서 부터 노드를 생성하는 함수
		
		if (this->next != tail) { // 노드의 헤드를 초기화 
			this->data = curr_data;
			this->next = tail;
			return this;
		}
		else {
			chain_node *temp = new chain_node;
			temp->next = tail;
			
			temp->data = curr_data;
			temp->next = tail;
			this->next = temp;
			
			return temp;
		}
	}
	
	friend int merger(chain &x, chain &y, chain &z); // friend를 사용함으로써 chain_node private를 공유
	int getdata() const{
		return data;
	}
	
	friend ostream &operator<<(ostream &os, chain &c);

};

class chain
{

private:
	chain_node *head; //메인에 선언하지않고 체인 원소를 헤드,테일 
	chain_node *tail;
public:
	chain() {
		head = new chain_node;  // 메모리 생성
		tail = new chain_node;
	}
	chain_node *gethead() const{
		
		return head;
	}
	chain_node *gettail() const {
	
		return tail;
	}
	void setnull() { // 노드를 합병할 경우 head의 NULL을 지표로 하여 공백리스트 구분 및 생성
		head = NULL;
		delete tail;
	}
	friend ostream &operator<<(ostream &os, chain &c);
	

};



int main() {
	chain x, y, z;
	chain_node *x_curr,*y_curr;
	x_curr = x.gethead();
	y_curr = y.gethead();
	for (int i = 0; i < 5; i++) {
		x_curr = x_curr->insert(i, x.gettail());
	}
	for (int i = 3; i < 8; i++) {
		y_curr = y_curr->insert(i, y.gettail());
	}
	
	cout << "x의 오름차순 :" << x << "\n";
	cout << "y의 오름차순 :" << y << "\n";
	
	merger(x, y, z);
	cout << "z의 오름차순 :" << z << "\n";
	cout << "x의 오름차순 :" << x << "\n";
	cout << "y의 오름차순 :" << y << "\n";
	
	
	return 0;
}

ostream &operator<<(ostream &os, chain &c) {
	chain_node *x = c.gethead();
	if (x == NULL) { // 공백일 경우
		os << "공백리스트입니다";
		return os;
	}
	while (x != c.gettail() ) {
		os << x->data ;
		os << "-";
		x = x->next;
	}


	return os;
}

int merger(chain &x, chain &y, chain &z) {
	chain_node *x_n = x.gethead();
	chain_node *y_n = y.gethead();
	chain_node *z_n = z.gethead();
	chain_node *pre_x, *pre_y;
	


	
	while ((x_n != x.gettail()) && (y_n != y.gettail())) { // X의 노드와 Y의노드 둘다 tail에 도달하지 않을경우
		if (x_n->getdata() < y_n->getdata()) {
			z_n = z_n->insert(x_n->getdata(), z.gettail());
			pre_x = x_n;
			x_n = x_n->next;
			delete pre_x;
			
		}
		else if (x_n->getdata() > y_n->getdata()) {
			z_n = z_n->insert(y_n->getdata(), z.gettail());
			pre_y = y_n;
			y_n = y_n->next;
			delete pre_y;
			
		}
		else {
			z_n = z_n->insert(x_n->getdata(), z.gettail());
			z_n = z_n->insert(y_n->getdata(), z.gettail());
			pre_x = x_n;
			pre_y = y_n;
			x_n = x_n->next;
			y_n = y_n->next;
			delete pre_x;
			delete pre_y;
			
		}
	}
	while( (x_n == x.gettail())^(y_n == y.gettail())) { // X의 노드 또는 Y의노드 둘중 하나가 tail에 도달한 경우
		if (x_n == x.gettail()) {
			z_n = z_n->insert(y_n->getdata(), z.gettail());
			pre_y = y_n;
			y_n = y_n->next;
			delete pre_y;
		}
		else if (y_n == y.gettail()) {
			z_n = z_n->insert(x_n->getdata(), z.gettail());
			pre_x = x_n;
			x_n = x_n->next;
			delete pre_x;
			
		}
	}
	x.setnull();
	y.setnull();
	return 0;
}
