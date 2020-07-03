#include <iostream>

using namespace std;
template <class T>

class cd_list { // circular double list
private:
	T data;
	cd_list *lnext; // left next
	cd_list *rnext; // right next 
public:
	cd_list() { data = 0, lnext = NULL ,rnext = NULL; } // cd_list 초기화 생성자
	cd_list(const cd_list &c) { data = c.data; lnext = c.lnext; rnext = c.rnext; } // cd_list 복사 생성자
	cd_list(T cdata, cd_list *ln, cd_list *rn) { data = cdata, lnext = ln, rnext = rn; } // cd_list 초기화 생성자2
	cd_list<T> *rinsert(T cdata, cd_list *head){    // rear insert
		if (this == head) { // 초기값
			cd_list<T> *node = new cd_list<T>(cdata,this,this);
			this->lnext = node;
			this->rnext = node;
			
			return node;
		}
		else {   
			cd_list<T> *node = new cd_list<T>(cdata, this, head);
		
			head->lnext = node;
			this->rnext = node;
			
			return node;
		}
	}
	cd_list<T> *finsert(T cdata, cd_list *head) { // front insert 
		if (this == head) { // 초기값 
			cd_list<T> *node = new cd_list<T>(cdata, this, this);
			
			this->lnext = node;
			this->rnext = node;
		
			return node;
		} 
	
		else {       
			 
				cd_list<T> *node = new cd_list<T>;
				node->data = cdata;
				
				cd_list<T> *next_node = head->rnext;
				
				next_node->lnext = node;
				head->rnext = node;
				node->rnext = next_node;
				node->lnext = head;
				
				return head->lnext; // 노드의 끝부분은 head->lnext 이므로..
			}
		
	};
	int getdata() const {
		return this->data;
	}
	cd_list<T> *ndelete(T cdata) { // 삭제 함수
		cd_list *curr = this->rnext;
		while (curr->data != cdata) {
			curr= curr->rnext;
		}
		cd_list *l_node = curr->lnext;
		cd_list *r_node = curr->rnext;
		l_node->rnext = r_node;
		r_node->lnext = l_node;
		delete curr;

		return 0;
	}

	~cd_list(){} // 소멸자(파괴자) 
	friend ostream& operator<<(ostream &os, cd_list *node); // 출력함수
};

int main() {
	cd_list<int> *head = new cd_list<int>;
	cd_list<int> *tail;
	tail = head;
	for (int i = 0; i < 4; i++) {
		tail = tail->finsert(3-i, head);
		
	}
	
	cout << "기존 연결리스트   :" << head << "\n";
	for (int i = 4; i < 8; i++) {
		tail = tail->rinsert(i, head);
	}
	cout << "기존 연결리스트   :" << head << "\n";
	head->ndelete(3);
	cout << "삭제한 연결리스트 :"<< head << "\n";

	return 0;
}

ostream& operator<<(ostream &os, cd_list<int> *node) { 
	cd_list<int> *head = node; // head의 위치를 저장.
	node = node->rnext;        // node가 head의 다음위치를 가르킨다.
	while (node != head) {     // node가 다음 head를 가르킬때까지 루프한다.

		os << node->data;
		node = node->rnext;

	}
		
	

	return os;
}
