#include <iostream>
#include<Windows.h>
#include <vector>
using namespace std;

struct item {
	string name;
	int price;
	int weight;
};

int backpack(vector<item>& items, vector<item>& selectedItems, int n) {
	int sz = items.size();
	vector<vector<int>> dp(sz + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= sz; ++i) {
		for (int w = 1; w <= n; ++w) {
			if (items[i - 1].weight <= w) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].price); 
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	int w = n;
	for (int i = sz; i > 0 && w > 0; i--) {
		if (dp[i][w] != dp[i - 1][w]) {
			selectedItems.push_back(items[i - 1]);
			w -= items[i - 1].weight;
		}
	}

	cout << endl;
	for (int i = 1 ; i <= sz; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	return dp[sz][n];
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введите вместимость рюкзака: ";
	cin >> N;

	cout << "Введите предметы: \n";

	vector<item> items;

	while (true) {
		item newItem;

		cout << "Название предмета: ";
		cin >> newItem.name;
		cout << "Цена: ";
		cin >> newItem.price;
		cout << "Вес: ";
		cin >> newItem.weight;

		items.push_back(newItem);

		cout << "1 - Продолжить; 0 - закончить \n";
		bool flag;
		cin >> flag;

		if (flag == false) {
			break;
		}
	}

	cout << "Список предметов: " << endl;
	for (auto itm : items) {
		cout << "Название: " << itm.name << "; Цена: " << itm.price << "; Вес : " << itm.weight << endl;
	}

	vector<item> selectedItems;
	int max = backpack(items, selectedItems, N);

	cout << "Максимальная стоимость предметов в рюкзаке: " << max << endl;
	cout << endl << "Выбранные предметы: " << endl;
	for (auto item : selectedItems) {
		cout << "Название: " << item.name << " Стоимость: " << item.price << " Вес: " << item.weight << endl;
	}
}