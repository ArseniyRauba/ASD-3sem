#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

void BFSMatrix(int startVertex);
void DFSMatrix(int startVertex);
void BFSList(queue<int>& q);
void DFSList(stack<int>& q);
void BFSEdge(queue<int>& q);
void DFSEdge(stack<int>& q);


bool visitedA[10] = { false };
bool visitedB[10] = { false };
bool visitedC[10] = { false };
bool visitedD[10] = { false };

const int MAX = 10;
int adjMatrix[MAX][MAX] = {

    {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},  
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},  
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},  
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},  
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},  
    {1, 0, 0, 1, 1, 0, 0, 0, 1, 0},  
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},  
    {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},  
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},  
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}   
};

vector<vector<int>> list = {
    {2, 5},
    {1, 7, 8},
    {8},
    {6, 9},
    {1, 6},
    {4, 9},
    {2, 8},
    {2, 3, 7},
    {4, 6, 10},
    {9}
};

vector<pair<int, int>> pairList = {
    {1, 2},
    {2, 7},
    {2, 8},
    {1, 5},
    {5, 6},
    {7, 8},
    {8, 3},
    {6, 4},
    {4, 9},
    {9, 6},
    {9, 10}
};

int main() {
    setlocale(LC_ALL, "ru");

    BFSMatrix(0);

    DFSMatrix(0);

    cout << "BFS Список смежности: ";
    queue<int>q1;
    int index = 1;
    q1.push(index);
    cout << index;
    BFSList(q1);
    cout << endl;

    cout << "DFS Список смежности: ";
    stack<int>s1;
    index = 1;
    s1.push(index);
    cout << index;
    DFSList(s1);
    cout << endl;

    cout << "BFS Список рёбер ";
    queue<int>q2;
    index = 1;
    q2.push(index);
    cout << index;
    BFSEdge(q2);
    cout << endl;

    cout << "DFS Список рёбер: ";
    stack<int>s2;
    index = 1;
    s2.push(index);
    cout << index;
    DFSEdge(s2);
    cout << endl;

    cout << "Большое О" << endl;
    cout << "Матрица смежности: " << 10 * 10 << endl;
    cout << "Список смежности: " << list.size() + 1 + 10 << endl;
    cout << "Список рёбер: " << list.size() + 1 + 10 << endl;

    return 0;
}

void BFSMatrix(int startVertex) {
    bool visited[MAX] = { false };
    queue<int> q; 

    visited[startVertex] = true;
    q.push(startVertex); 

    cout << "BFS Matrix: ";
    while (!q.empty()) {
        int v = q.front();
        q.pop(); 
        cout << v + 1 << " "; 

        for (int i = 0; i < MAX; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                visited[i] = true; 
                q.push(i);
            }
        }
    }
    cout << endl;
}

void VspomMatrix(int v, bool visited[]) {
    visited[v] = true;
    cout << v + 1 << " ";

    for (int i = 0; i < MAX; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            VspomMatrix(i, visited);
        }
    }
}

void DFSMatrix(int startVertex) {
    bool visited[MAX] = { false };
    cout << "DFS Matrix: ";
    VspomMatrix(startVertex, visited);
    cout << endl;
}

void BFSList(queue<int>& q) {

    while (!q.empty()) {
        int index = q.front();
        q.pop();

        if (!visitedA[index - 1]) {

            if (index != 1) {
                cout << " " << index;
            }

            visitedA[index - 1] = true;

            for (int i = 0; i < list[index - 1].size(); i++) {
                q.push(list[index - 1][i]);
            }
        }
    }
}

void DFSList(stack<int>& s) {

    while (!s.empty()) {
        int index = s.top();
        s.pop();

        if (!visitedB[index - 1]) {

            if (index != 1) {
                cout << " " << index;
            }

            visitedB[index - 1] = true;

            for (int i = 0; i < list[index - 1].size(); i++) {
                s.push(list[index - 1][i]);
            }
        }
    }
}

void BFSEdge(queue<int>& q) {

    while (!q.empty()) {
        int index = q.front();
        q.pop();

        if (!visitedC[index - 1]) {

            if (index != 1) {
                cout << " " << index;
            }

            visitedC[index - 1] = true;

            for (int i = 0; i < pairList.size(); i++) {

                if (pairList[i].first == index) {
                    q.push(pairList[i].second);
                }

                else if (pairList[i].second == index) {
                    q.push(pairList[i].first);
                }
            }
        }
    }
}

void DFSEdge(stack<int>& s) {

    while (!s.empty()) {
        int index = s.top();
        s.pop(); 

        if (!visitedD[index - 1]) {

            if (index != 1) {
                cout << " " << index;
            }

            visitedD[index - 1] = true;

            for (int i = 0; i < pairList.size(); i++) {

                if (pairList[i].first == index) {
                    s.push(pairList[i].second);
                }
                else if (pairList[i].second == index) {
                    s.push(pairList[i].first);
                }
            }
        }
    }
}
