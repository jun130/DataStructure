#include <iostream>
#include <cstring>
#include <fstream>

//#include <fcntl.h>
//#include <unisted.h>
//git push exercise@@@@@@@@@@@
using namespace std;
class in_to_post;
ifstream fi;
ofstream fo;




class in_to_post { // infix -> prefix
private:
	int atok[30]; // 숫자 저장 토큰배열
	char *btok; // 연산자 저장 토큰
	char *ctok; // 문자 저장 토큰
public:
	void convert(char *infix) {
		int size = strlen(infix) + 1; // 사용자가입력한 문자열의 크기
		
		int bsize = size - 2;
		int a_size = 0;
		int c_size = 0;
		int a_count = 0; // 괄호의 수를 계산할 count 변수
		int c_count = 0;


		btok = new char[size]; // infix 문자열만큼 할당
		ctok = new char[size];

		
		btok[size - 1] = '\0'; // 문자열의 끝인 '\0'을 입력
		ctok[size - 1] = '\0';

		for (int i = 0; i < size - 1; i++) {

			switch (infix[i]) {


			case '(':
				btok[bsize] = infix[i];
				bsize--;

				break;
			case '%':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*') || (btok[bsize + 1] == '%')) {
					atok[a_size] = btok[bsize + 1];
					ctok[c_size] = btok[bsize + 1];
					a_size++;
					c_size++;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;

				break;
			case '*':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*') || (btok[bsize + 1] == '%')) {
					atok[a_size] = btok[bsize + 1];
					ctok[c_size] = btok[bsize + 1];
					a_size++;
					c_size++;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;

				break;
			case '/':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*') || (btok[bsize + 1] == '%')) {
					atok[a_size] = btok[bsize + 1];
					ctok[c_size] = btok[bsize + 1];
					a_size++;
					c_size++;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;

				break;
			case '+':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*' ) || (btok[bsize + 1] == '+') || (btok[bsize + 1] == '-') || (btok[bsize + 1] == '%')) {
					atok[a_size] = btok[bsize + 1];
					ctok[c_size] = btok[bsize + 1];
					a_size++;
					c_size++;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;
				break;
			case '-':
				while ((btok[bsize + 1] == '/') || (btok[bsize + 1] == '*') || (btok[bsize + 1] == '+') || (btok[bsize + 1] == '-') || (btok[bsize + 1] == '%')) {
					atok[a_size] = btok[bsize + 1];
					ctok[c_size] = btok[bsize + 1];
					a_size++;
					c_size++;
					bsize++;
				}
				btok[bsize] = infix[i];
				bsize--;
				break;
			case ')':
				atok[a_size] = btok[bsize + 1]; // (은 전위표기식에 넣을필요없으므로 연산자만 넣는다
				ctok[c_size] = btok[bsize + 1];
				bsize = bsize + 2; // ')' 의 위치로
				a_size++;
				c_size++;
				a_count = a_count + 2; // 사용자가 입력한 괄호의수 2개
				c_count = c_count + 2;

				break;
			case ' ':
				a_count++;
				c_count++;
				break;
			default:
				if (infix[i+ 1] >= '0' && infix[i + 1] <= '9') {
					atok[a_size] = 10 * (infix[i] - '0') + (infix[i+ 1] - '0');
					ctok[c_size+1] = infix[i+1];
					ctok[c_size] = infix[i];
					c_size++;
					a_count++;
					i++;					
					
				}
				else {
					atok[a_size] = infix[i] - '0';
					ctok[c_size] = infix[i];
				}
			
				a_size++;
				c_size++;
				break;
			}

		}

		

		int b_size = bsize;

		while (a_size != size - 1 - a_count) { // size = strlen(atok)
			bsize++; 
			atok[a_size] = btok[bsize];
			
			
			a_size++;

		}
		while (c_size != size - 1 - c_count) { // size = strlen(atok)
			b_size++;
			
			ctok[c_size] = btok[b_size];

			c_size++;

		}

		cout << "\n후위표기식 int형배열: ";
		for (int i = 0; i < size - a_count-1; i++) {
			cout << atok[i] << '\n';
		}
		
		cout << "\n후위표기식 : ";
		for (int i = 0; i < size - c_count - 1; i++) {
			cout << ctok[i];
			fo << ctok[i];
			
		}
		cout << "\n";
		fo << "\n";
	
		//write(fd,ctok,strlen(ctok) );
		//write(fd, '\n', 1);
	}


	int calcul() {
		int result = 0; // 계산값
		
		int size = strlen(ctok); // . 
		int token[30];

		int num = 0; // token element number
		for (int i = 0; i<size; i++) { // 토큰에 스택하는 루프
									   //cout << atok[i];

			if (atok[i] == 42) { // * 인 경우 
				int num04 = (token[num - 2] * token[num - 1]);
				token[num - 2] = num04;
				result = num04;
				num = num - 1;
			}
			else if (atok[i] == 37) { // / 인경우
				int num05 = (token[num - 2]) % (token[num - 1]);
				token[num - 2] = num05;

				result = num05;
				num = num - 1;
			}
			else if (atok[i] == 43) { // + 인경우
				
				int num01 = (token[num - 2] + token[num - 1]);
				token[num - 2] = num01;

				result = num01;
				num = num - 1;
			}
			else if (atok[i] == 45) { // - 인경우
				int num02 = (token[num - 2] - token[num - 1]);
				token[num - 2] = num02;
				result = num02;

				num = num - 1;

			}
			else if (atok[i] == 47) { // / 인경우
				int num03 = (token[num - 2]) / (token[num - 1]);
				token[num - 2] = num03;
				result = num03;
				num = num - 1;
			}
			else { // 연산자가 아닌경우
				token[num] = atok[i];
				num++;
			}
		}
		cout << "계산값 : " << result << "\n";
		//write(fd,result, sizeof(result));
		fo << result;
		return 0;
	}
	

};



int main() {
	char infix[50];
	//cout << "중위표기식을 입력하시오 (30자 이내) :";
	//cin.getline(infix, sizeof(infix));
	fi.open("input01.txt", ios::in);
	fo.open("input01_out.txt", ios::out);

	fi.getline(infix, sizeof(infix));

	
	
	
	in_to_post postfix;
	
	postfix.convert(infix);
	postfix.calcul();
	fi.close();
	fo.close();
	
	return 0;
}
