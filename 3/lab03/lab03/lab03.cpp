#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
	vector<int> dist(graph.size(), INF);
	dist[start] = 0;
	vector<bool> visited(graph.size(),false);

	for (int i = 0; i < graph.size(); i++) {
		int nearest = -1;
		
		for (int j = 0; j < graph.size(); j++) {
			if (!visited[j] && (nearest == -1 || dist[nearest] > dist[j])) {
				nearest = j;
			}
		}
		visited[nearest] = true;

		for (const pair<int,int>& edge : graph[nearest]) {
			int to = edge.first;
			int weight = edge.second;
			if (dist[to] > dist[nearest] + weight) {
				dist[to] = dist[nearest] + weight;
			}
		}
	}
	return dist;
}

int main() {
	char startlet;
	const int v = 9;
	vector<vector<int>> matrix = {
		//A B C D E F G H I 
		{0,7,10,0,0,0,0,0,0},//A
		{7,0,0,0,0,9,27,0,0},//B
		{10,0,0,0,31,8,0,0,0},//C
		{0,0,0,0,32,0,0,17,21},//D
		{0,0,31,32,0,0,0,0,0},//E
		{0,9,8,0,0,0,0,11,0},//F
		{0,27,0,0,0,0,0,0,15},//G
		{0,0,0,17,0,11,0,0,15},//H
		{0,0,0,21,0,0,15,15,0} //I
	};

	vector<vector<pair<int, int>>> grapH(v);

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (matrix[i][j] != 0) {
				grapH[i].push_back({ j,matrix[i][j] });
			}
		}
	}

	cout << "Enter a start vertex(A-I): ";
	cin >> startlet;
	int start = startlet - 'A';

	vector<int> dist = dijkstra(grapH, start);

	cout << "Minimal distance from vertex " << startlet << ": " << endl;
	for (int i = 0; i < v; i++) {
		cout << "To vertex: " << char(i + 'A') << ": " << (dist[i] == INF ? -1 : dist[i]) << endl;
	}

}