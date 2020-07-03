#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <ctime>
using namespace std;

int *nsarr; // not sort array;
int *arr;   // nsarr -> array;
int *qkarr; // quick sort array;

int *mgarr; // merge sort array;
queue<int> *que; // radix sort array;
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
};

void my_strcat(char *A, char *B)
{
	while (*A) {
		*A++;
	}

	while (*A = *B)
	{
		*A++;
		*B++;
	}
};

void stok(char *a, char *b[]) { // space 구분 토크
	int prev = 0;
	int k = 0;
	int j = 0;
	char copy[2] = " ";
	my_strcat(a, copy);

	for (int i = 0; a[i] != '\0'; i++) {

		if (a[i] == ' ') {
			a[i] = '\0';
			*(b + j) = new char[20];
			while (a[prev] != '\0') {

				*(*(b + j) + k) = a[prev];
				prev++;
				k++;

			}
			prev++;
			*(*(b + j) + k) = '\0';

			k = 0;
			j++;

		}
	}

};

int insertSort(int nsarr[],int size) {
	int temp;
	int j;
	
	for (int i = 1; i < size; i++) {
		temp = arr[i];
		j = i;
		while (j > 0 && temp <= arr[j - 1]) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
	

	return 0;
};

int bubbleSort(int nsarr[], int size) {
	int temp;
	for (int i = 1; i < size-1; i++) {
		for (int j = 0; j < size-i; j++) {
			temp = arr[j];
			if (arr[j] > arr[j + 1]) {
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			
		}
	}
	

	return 0;
};

int selectSort(int nsarr[], int size) {
	int Min;
	int temp;
	for (int i = 0; i < size-1; i++) {
		Min = i;
		for (int j = i+1; j < size; j++) {
			if (arr[i] > arr[j]) {
				Min = j;

				temp = arr[i];
				arr[i] = arr[Min];
				arr[Min] = temp;
			}

		}
	}

	return 0;
};

int quickSort(int arr[], int left, int right) {

	int l = left;
	int r = right;
	int pivot = arr[(l + r) / 2];
	int temp;
	do {
		while (arr[l] < pivot) 
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r) {
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
	} while (l <= r);

	if (left < r) {
		quickSort(arr, left, r);
	}
	if (right > l) {
		quickSort(arr, l, right);
	}
	
	
	

	return 0;
};

void merge(int arr[], int size, int start, int end) {
	int mid = (start + end) / 2;
	int i = start,j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			mgarr[k++] = arr[i++];
		else
			mgarr[k++] = arr[j++];
	}
	while (i <= mid)
		mgarr[k++] = arr[i++];
	while (j <= end)
		mgarr[k++] = arr[j++];

	for (int i = start; i <= end; i++) {
		arr[i] = mgarr[i];
	}
};

void mergeSort(int arr[], int size, int start, int end){
	

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr,size,start, mid);
		mergeSort(arr,size,mid + 1, end);
		merge(arr,size ,start, end);
	}
	
};

void radixSort(int nsarr[],int size) {
	
	int digNum = log10(size) + 1;
	int num,k,mod;
	mod = 1;
	for (int i = 0; i < digNum; i++) {
		k = 0;
		
		for (int j = 0; j < size; j++) {
			num =(arr[j]/mod)%10;
			que[num].push(arr[j]);
			
		}
		
	

		for (int l = 0; l < 10; l++) {
			while (que[l].size() > 0) {
				arr[k] = que[l].front();
				que[l].pop();		
				k++;
			}
			
		}
		mod = mod * 10;
	}

}

void heapSort(int nsarr[], int size) {
	
	
	for (int i = 0; i < size; i++) {
		int c = i;
		do {
			int root = (c-1) / 2;
			if (arr[root] < arr[c]) {
				int temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	for (int i = size - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if (arr[c] < arr[c+1] && c <i-1)
				c++;
			if (arr[root] < arr[c] && c < i) {
				int temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			root = c;
			
			
		} while (c < i);
	}
}


int main(int argc, char* argv[]) {

	ifstream fi;
	ofstream fo;
	fi.open(argv[1], ios::in);
	fo.open("ResultClk.txt", ios::out);
	ios_base::sync_with_stdio(false); // 속도를 높여줌


	int Flength = sizeof(argv[1])-1;
	char *str;
	char str2[7];
	int convert_str = 0;
	int size;
	int i = 0;
	
	for (int m = 4; m < Flength; m++) {
		str2[m-4] = argv[1][m];
	}

	size = atoi(str2);
	
	str = new char[size];
	nsarr = new int[size];
	arr = new int[size];
	mgarr = new int[size];
	que = new queue<int>[size];

	fi.getline(str, size);
	while ( fi.getline(str,size,' ')) { //입력받는부분;
		if (convert_str == -1) 
			break;
		
		convert_str = atoi(str);
		
		nsarr[i] = atoi(str);
		arr[i] = nsarr[i];
		i++;
	
	}


	

	
	clock_t s, e;
	double work_time;

	cout << "insertSort\n";
	s = clock();
	insertSort(nsarr,size);
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";

	cout << "bubbleSort\n";
	s = clock();
	bubbleSort(nsarr, size);
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";


	cout << "selectSort\n";
	s = clock();
	selectSort(nsarr, size);
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";


	cout << "quickSort\n";
	s = clock();
	quickSort(arr, 0, size-1);
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";


	cout << "mergeSort\n";
	s = clock();
	mergeSort(arr,size, 0, size - 1);  
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";


	cout << "radixSort\n";
	s = clock();
	radixSort(arr, size); 
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";


	cout << "heapSort\n";
	s = clock();
	heapSort(arr, size); 
	e = clock();
	work_time = (double)(e - s) / CLOCKS_PER_SEC;
	fo << work_time << "\n";

	
	
	fi.close();
	fo.close();
}
