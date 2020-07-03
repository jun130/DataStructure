#include <iostream>
#include <string>
using namespace std;

class in_to_pre { // infix -> prefix
private:
	char *atok; // 문자 저장 토큰
	char *btok; // 연산자 저장 토큰
public:
	void convert(char *infix) {
		int size =strlen(infix)+1; // 사용자가입력한 문자열의 크기
		int asize = size - 2; // 문자열의끝인 '\0'을 제외한 배열 사이즈
		int bsize = size - 2;
		int count = 0; // 괄호의 수를 계산할 count 변수
	
		atok = new char[size]; // infix 문자열만큼 할당
		btok = new char[size];
		
		atok[size - 1] = '\0'; // 문자열의 끝인 '\0'을 입력
		btok[size - 1] = '\0';
		
		for (int i = size-2; i > -1; i--) {
			
			switch (infix[i]) {
		
			case '#': 
				atok[count] = infix[i];
				break;
			case '(':
				atok[asize] = btok[bsize + 1]; // (은 전위표기식에 넣을필요없으므로 연산자만 넣는다
				bsize= bsize+2; // ')' 의 위치로
				asize--;
				count = count + 2; // 사용자가 입력한 괄호의수 2개
				break;
			case '*':
				
					btok[bsize] = infix[i];
					bsize--;
				
				break;
			case '/':
				
				    btok[bsize] = infix[i];
				    bsize--;
				
				break;
			case '+':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*')) {
					atok[asize] = btok[bsize + 1];
					asize--;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;
				break;
			case '-':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*')) {
					atok[asize] = btok[bsize + 1];
					asize--;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;
				break;
			case ')':
				btok[bsize] = infix[i]; 
				bsize--;
				break;
			default :
				atok[asize] = infix[i];
				asize--;
				break;
			}

		}
		int error = 1;
		if (atok[count] != '#') { // 예외처리 #을 사용자가 입력 안할경우
			throw error;
		}
		while (asize != count) { 
			bsize++;
			atok[asize] = btok[bsize];
			asize--;
			
		}

		
		cout << "\n전위표기식: ";
		for (int i = count; i < strlen(atok); i++) {
			cout << atok[i];
		}
		cout << "\n";
		
	}
};


int main() {
	char infix[30];
	cout << "중위표기식을 입력하시오 (30자 이내) :";
	cin >> infix;
	in_to_pre prefix;
	try {
		prefix.convert(infix);
	}
	catch (int a) // 예외처리 에러 받는부분
	{
		if (a == 1) {
			cout << "please # input at infix notation";
		}
	}
	return 0;
}
