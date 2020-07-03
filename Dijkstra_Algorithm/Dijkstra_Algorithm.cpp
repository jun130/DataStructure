#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX_VERTEX 1002222222222220 // 최대 정점 번호
#define INF 1000 // 맥스 가중치 
// 변수정의
ifstream fi;
ofstream fo;
char str[20]; 
char *lap1[4]; // 정점,가중치 저장
char *lap2[3]; // 시작점,마지막점 저장

int line = 0;
int state = 0; // 0 이면 정점과 엣지갯수를 입력받음
			 // 1 이면 정점과 정점간의 가중치를 입력받음
			 // 2 이면 입력이 시작점과 종점을 입력받음
int convert_str;
int vertex; // 정점 수
int edge;  // 간선 수
int start_vertex; // 시작 정점
int last_vertex; // 마지막 정점
int pre_vertex; // 이전 정점 
int next_vertex; // 다음 정점
int weight; // 가중치


int min_leng[MAX_VERTEX]; // 최소거리
bool visit[MAX_VERTEX]; // 방문여부

int min_dist[MAX_VERTEX];
int stack_dist[MAX_VERTEX];
int stack_size=0;

vector<pair<int, int>> adj[MAX_VERTEX]; // 인접행렬 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pr_queue; // 우선순위큐 




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
}

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

}

int main() {

	fi.open("input.txt", ios::in);
	fo.open("output.txt", ios::out);
	ios_base::sync_with_stdio(false); // 속도를 높여줌
	//fi.getline(vertex, sizeof());


	// 입력받는 부분
	
	while (fi.getline(str, 20)) {
		
		convert_str = atoi(str);
		if (state == 0) {
			if (line == 0) {
				vertex = convert_str;
				
			}
			else if (line == 1) {
				edge = convert_str;
			
			}
			
			line++;
			
			if (line == 2) {
				state = 1;

				continue;
			}
		}
		else if (state == 1) {

			if (convert_str == -1) {
				state = 2;

				continue;
			}

			stok(str, lap1);

			pre_vertex = atoi(lap1[0]);
			next_vertex = atoi(lap1[1]);
			weight = atoi(lap1[2]);

			

			
			adj[pre_vertex].push_back(make_pair(weight, next_vertex));
			
			
		}
		else if (state == 2) {
			if (convert_str == -9) {
				break;
			}
			stok(str, lap2);

			start_vertex = atoi(lap2[0]);
			last_vertex = atoi(lap2[1]);
			
			
		

		}

	}

	

	
	for (int k = 1; k <= vertex; k++) {
		min_leng[k] = INF;
	}

	
	min_leng[start_vertex] = 0;
	pr_queue.push(make_pair(0, start_vertex));

	
	while (!pr_queue.empty()) {
		
		int length = pr_queue.top().first;
		int curr_vertex = pr_queue.top().second;
		
		pr_queue.pop();
		
		if (min_leng[curr_vertex] < length) { continue; }
		if (min_leng[curr_vertex] == length && visit[curr_vertex] == true) { continue; }
		
		visit[curr_vertex] = true;
		
		if (adj[curr_vertex].size() == 0) {
			continue;
		}
		for (int j = 0; j < adj[curr_vertex].size(); j++) {
			
			
			int next_length = adj[curr_vertex][j].first;
			int next = adj[curr_vertex][j].second;
			
			if (min_leng[next] > next_length + length) {
				min_leng[next] = next_length + length;
				pr_queue.push(make_pair(next_length + length, next));
				min_dist[next] = curr_vertex;
				
			}
			
		}
		
	}
	
	// 출력하는 부분
	
	if (min_leng[last_vertex] >= INF) { //최단거리가 존재하지않음.
		fo << "have not minimum distance" <<"\n" <<  "oo" << "\n";
		cout << "have not minimum distance" << "\n" << "oo" << "\n";
	}
	else {
		int last = last_vertex; // 마지막 정점 저장

		while (min_dist[last] != start_vertex) {
			//cout << min_dist[last] << "입니다\n";
			stack_dist[stack_size] = min_dist[last];
			last = min_dist[last];
			stack_size++;
		}
		fo << start_vertex << " : " << last_vertex << " : => ";
		fo << start_vertex << "->";
		cout<< start_vertex << " : " << last_vertex << " : => ";
		cout << start_vertex << "->";
		for (int i = stack_size - 1; i > -1; i--) {
			fo << stack_dist[i] << "->";
			cout << stack_dist[i] << "->";
		}
		fo << last_vertex << "\n";
		cout << last_vertex << "\n";
		double min_distance = min_leng[last_vertex];
		fo << min_distance;
		cout << min_distance;
	}
	
	

	fi.close();
	fo.close();

	return 0;
}
