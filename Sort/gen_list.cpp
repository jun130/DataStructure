#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int atoi(char *st) // 문자열을 정수형으로
{
	int i = 0, j = 0;
	if (*st == '-' || isdigit(*st)) {
		if (*st == '-') j = 1, st++;
		while (isdigit(*st))
		{
			i = i * 10 + (*(st)) - 48;
			st++;
		}
		if (j == 1) return -i;
		else return i;
	}
	else
		return 0;
}

int main(int argc, char* argv[]) {
	ofstream fo;
	int ranNum = atoi(argv[1]);
	char FN[11] = "list";
	for (int i = 0; i < sizeof(argv[1])-1; i++) {
		FN[i + 4] = argv[1][i];
	}
	fo.open(FN, ios::out);

	
	
	fo << ranNum << "\n";
	for (int i = 0; i <ranNum; i++) {
		fo << rand();
		fo << " ";
	}
	fo.seekp(-1, SEEK_CUR);
	fo << "\n" << -1;
	

	fo.close();

}
