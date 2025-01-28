#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

#define INF  9999;

vector<vector<int>> matrix = {
	//1 2 3 4 5 6 7 8  
	 {0,2,0,8,2,0,0,0},//1
	 {2,0,3,10,5,0,0,0},//2
	 {0,3,0,0,12,0,0,7},//3
	 {8,10,0,0,14,3,1,0},//4
	 {2,5,12,14,0,11,4,8},//5
	 {0,0,0,3,11,0,6,0},//6
	 {0,0,0,11,4,6,0,9},//7
	 {0,0,7,0,8,0,9,0},//8
};

void Prima() {
	int min;
	int rows;
	int colums;

	bool selected[8];
	memset(selected, false, sizeof(selected));
	selected[0] = true;

	int v = 0;

	cout << "Edges : Weight" << endl;
	while (v < 7) {
		min = INF;
		rows = 0;
		colums = 0;

		for (int i = 0; i < 8; i++) {
			if (selected[i]) {
				for (int j = 0; j < 8; j++) {
					if (!selected[j] && matrix[i][j]) {
						if (min > matrix[i][j]) {
							min = matrix[i][j];
							rows = i;
							colums = j;
						}
					}
				}
			}
		}

		cout << rows + 1 << " - " << colums + 1 << " : " << matrix[rows][colums];
		cout << endl;
		selected[colums] = true;
		v++;
	};
}

struct Edge {
	int src, dest, weight;
};

int find(int parent[], int i) {
	if (parent[i] == i) {
		return i;
	}
	return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
	int xroot = find(parent, x);
	int yroot = find(parent, y);

	if (rank[xroot] < rank[yroot]) {
		parent[yroot] = xroot;
	}
	else if (rank[yroot] < rank[xroot]) {
		parent[yroot] = xroot;
	}
	else {
		parent[yroot] = xroot;
		rank[xroot]++;
	}
}

bool compare(Edge a, Edge b) {
	return a.weight < b.weight;
}

void Kruskal() {
	vector <Edge> edges;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (matrix[i][j] != 0) {
				Edge edge = { i, j, matrix[i][j] };
				edges.push_back(edge);
			}
		}
	}

	sort(edges.begin(), edges.end(), compare);

	int parent[8];
	int rank[8];

	for (int i = 0; i < 8; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	vector<Edge> result;
	int e = 0;

	for (auto& edge : edges) {
		if (e == 7)
			break;

		int x = find(parent, edge.src);
		int y = find(parent, edge.dest);


		if (x != y) {
			result.push_back(edge);
			unionSets(parent, rank, x, y);
			e++;
		}
	}

	int minimumCost = 0;
	for (auto& edge : result) {
		cout << edge.src + 1 << " -- " << edge.dest + 1 << ": " << edge.weight << endl;
		minimumCost += edge.weight;
	}
	cout << '\n' << '\n' << "weight:" << minimumCost << endl;
}

int main() {
	int m = 16;
	int n = 8;
	int num = m - n + 1;
	cout << "Cyclomatic number: " << num << endl;
	Prima();
	cout << "Prima: " << endl;
	cout << "Kruskal: " << endl;
	Kruskal();
}