#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e10;

vector<vector<int>> distInit = {
	//1  2  3  4  5  6
	 {0,28,21,59,12,27},//1
	 {7,0,24,INF,21,18},//2
	 {9,32,0,13,11,INF},//3
	 {8,INF,5,0,16,INF},//4
	 {14,13,15,10,0,22},//5
	 {15,18,INF,INF,6,0}//6
};

vector<vector<int>> vertices = {
	{0,2,3,4,5,6},
	{1,0,3,4,5,6},
	{1,2,0,4,5,6},
	{1,2,3,0,5,6},
	{1,2,3,4,0,6},
	{1,2,3,4,5,0},
};

void getPath(vector<vector<int>>& vertices, int start, int finish) {

	if (vertices[start][finish] == finish + 1) {
		cout << finish + 1 << " ";
		return;
	}
	getPath(vertices, start, vertices[start][finish] - 1);
	cout << finish + 1 << " ";
}

void Floyd() {
	for (int v = 0; v < 6; v++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (distInit[i][v] + distInit[v][j] < distInit[i][j] && i != j && j != v && i != v) {
					distInit[i][j] = distInit[i][v] + distInit[v][j];
					vertices[i][j] = v + 1;
				}
			}
		}
	}

	cout << "D: " << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << distInit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------" << endl;

	cout << "S: " << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << vertices[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------" << endl;
}

int main(){
	Floyd();

	int start, finish;
	
	cout << "Enter a start vertex(1-6): ";
	cin >> start;

	cout << "Enter a finish vertex(1-6): ";
	cin >> finish;

	if (start < 1 || start>6 || finish < 1 || finish>6) {
		cout << "Invalid vertices!";
	}

	cout << "Distance: " << distInit[start - 1][finish - 1] << endl;

	cout << "Shorter way: ";
	cout << start << " ";
	getPath(vertices, start - 1, finish - 1);
	cout << endl;
}