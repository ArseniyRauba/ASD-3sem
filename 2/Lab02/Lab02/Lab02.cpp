#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void listBFS(queue<int> &q);
void listDFS(stack<int>&s);
void matrixBFS(int startVertex);
void matrixDFS(int startVertex);
void pairListBFS(queue<int>& q);
void pairListDFS(stack<int>& s);

const int MAX = 10;

vector<vector<int>> list = {
	{2, 5},
	{1, 7, 8},
	{8},
	{6, 9},
	{1, 6},
	{4, 5, 9},
	{2, 8},
	{2, 3, 7},
	{4, 6, 10},
	{9}

};

int matrix[MAX][MAX] =
{
	{0,1,0,0,1,0,0,0,0,0},
	{1,0,0,0,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,1,0,0,1,0},
	{1,0,0,0,0,1,0,0,0,0},
	{0,0,0,1,1,0,0,0,1,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,1,0,0,0,1,0,0,0},
	{0,0,0,1,0,1,0,0,0,1},
	{0,0,0,0,0,0,0,0,1,0}
};

vector<pair<int, int>> pairList = {
	{1,2},
	{1,5},
	{2,7},
	{2,8},
	{3,8},
	{4,6},
	{4,9},
	{5,6},
	{6,9},
	{7,8},
	{9,10},

};

int main() {
	setlocale(LC_ALL, "rus");

	cout << "Список ребер, BFS: ";
	queue<int>q1;
	int v = 1;
	q1.push(v);
	cout << v;
	pairListBFS(q1);
	cout << endl;

	cout << "Список ребер, DFS: ";
	stack<int>s1;
	v = 1;
	s1.push(v);
	cout << v;
	pairListDFS(s1);
	cout << endl;

	cout << "Матрица, BFS: ";
	matrixBFS(1);

	cout << "Матрица, DFS: ";
	matrixDFS(1);

	cout << "Список смежности, BFS: ";
	queue<int>q2;
	v = 1;
	q2.push(v);
	cout << v;
	listBFS(q2);
	cout << endl;

	cout << "Список смежности, BFS: ";
	stack<int>s2;
	v = 1;
	s2.push(v);
	cout << v;
	listDFS(s2);
	cout << endl;
	pairListDFS(s2);

	return 0;
}
	
void listBFS(queue<int>&q) {
	bool visited[MAX] = { false };

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v + 1 << " ";

		if (!visited[v - 1]) {
			
			if (v != 1) {
				cout << " " << v;
			}

			visited[v - 1] = true;

			for (int i = 0; i < list[v - 1].size(); i++) {
				q.push(list[v - 1][i]);
			}
		}
	}

}

void listDFS(stack<int>&s) {
	bool visited[MAX] = { false };

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		if (!visited[v - 1]) {
			cout << " " << v;
		}

		visited[v - 1] = true;

		for (int i = 0; i < list[v - 1].size(); i++) {
			s.push(list[v - 1][i]);
		}
	}
}

void matrixBFS(int startVertex) {
	bool visited[MAX] = { false };
	queue<int> q;

	visited[startVertex] = true;
	q.push(startVertex);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v + 1 << " ";

		for (int i = 0; i < MAX; i++) {
			if (matrix[v][i] == 1 && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

}

void matrixDFS(int startVertex) {
	bool visited[MAX] = { false };
	stack<int> s;

	visited[startVertex] = true;
	s.push(startVertex);

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		if (!visited[v - 1]) {

			if (v != 1) {
				cout << " " << v;
			}

			visited[v - 1] = true;

			for (int i = 0; i < MAX; i++) {
				s.push(matrix[v - 1][i]);
			}
		}

	}
}

void pairListBFS(queue<int>&q) {
	bool visited[MAX] = { false };

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		if (!visited[v - 1]) {
			cout << " " << v;
		}

		visited[v - 1] = true;

		for (int i = 0; i < pairList.size(); i++) {
			if (pairList[i].first == v) {
				q.push(pairList[i].second);
			}
			else if (pairList[i].second == v) {
				q.push(pairList[i].first);
			}
		}
	}
}

void pairListDFS(stack<int>&s) {
	bool visited[MAX] = { false };

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		if (!visited[v - 1]) {
			cout << " " << v;
		}

		visited[v - 1] = true;

		for (int i = 0; i < pairList.size(); i++) {
			if (pairList[i].first == v) {
				s.push(pairList[i].second);
			}
			else if (pairList[i].second == v) {
				s.push(pairList[i].first);
			}
		}
	}
}