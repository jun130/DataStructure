#include <iostream>

using namespace std;


class prefix{
private:
	int *token;
	

public :
	prefix() {};
	
	int calcul(char *str) { // 계산하는 함수
		int result = 0 ; // 계산값
		int size = strlen(str);
		token = new int[size];
		int num = size-1 ; // token element number
		for (int i = size ; i>-1; i--) { // 토큰에 스택하는 루프
			
			if (str[i] == 35) { // # 인 경우 루프 종료
				cout << "계산값 : " << result << "\n";
				
				return 0;
			}
			else if (str[i] == 42) { // * 인 경우 
				int num04 = (token[num + 1]* token[num + 2]);
				token[num + 2] = num04;
				result = num04;
				num = num + 1;
			}
			else if(str[i] == 43) { // + 인경우
				int num01 = (token[num + 1] + token[num + 2]);
				token[num + 2] = num01;
				
				result = num01;
				num = num + 1;
					}
			else if(str[i] == 45){ // - 인경우
				int num02 = (token[num + 1] - token[num + 2]);
				token[num + 2] = num02;
				result = num02;
				
				num = num + 1;

			}
			else if(str[i] == 47){ // / 인경우
				int num03 = (token[num + 1]) / (token[num + 2]);
				token[num + 2] = num03;
				result = num03;
				num = num + 1;
			}
			else { // 연산자가 아닌경우
				token[num] = str[i] - '0';
				num--;
			}
		}
		
	}
};


int main() {
	prefix e;
	char str[30];
	cout << "정수 전위표기식을 넣으시오.(30자 이내)\n";
	cin >> str;
	
	
	e.calcul(str);
return 0;
}
