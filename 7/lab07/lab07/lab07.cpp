#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> longest(const vector<int>& numbers) {
	if (numbers.empty()) {
		return{};
	}

	int sz = numbers.size();
	int len = 1;
	int index = 0;
	vector<int> sub(sz, 1);
	vector<int> vosst(sz, -1);

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < i; ++j) {
			if (numbers[i] > numbers[j] && sub[i] < sub[j] + 1) {
				sub[i] = sub[j] + 1;
				vosst[i] = j;
			}
		}
		if (sub[i] > len) { //5 10 12 24
			len = sub[i];
			index = i;
		}
	}

	vector<int> restore(len);
	int curIndex = index;
	
	for (int i = len - 1; i >= 0; --i) {
		restore[i] = numbers[curIndex];
		curIndex = vosst[curIndex];
	}
	return restore;
}

int main() {
	int N;
	cout << "Enter a number of elements: ";
	cin >> N;
	vector<int> num(N);

	cout << "Enter elements: ";
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	vector<int> res = longest(num);
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}