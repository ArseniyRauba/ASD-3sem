#include <iostream>
#include <chrono>

using namespace std;

void hanoi(int diskNum, int from, int to);

int num;

int main() {

	int disks, startKern, finishKern;
	cout << "Enter number of disks: ";
	cin >> disks;
	if (disks == 0) {
		cout << "Wrong number of disks";
		return 0;
	}

	cout << "Enter number of start kern: ";
	cin >> startKern;
	if (startKern > 3 || startKern < 1) {
		cout << "Wrong number of kern";
		return 0;
	}

	cout << "Enter number of finish kern: ";
	cin >> finishKern;
	if (finishKern > 3 || startKern < 1) {
		cout << "Wrong number of kern";
		return 0;
	}

	float a = clock();
	hanoi(disks, startKern, finishKern);
	float b = clock();

	cout << "Number of steps: " << num << endl;
	cout << "Time: " << (b - a) / 1000;

	return 0;
}

void hanoi(int diskNum, int from, int to) {
	int temp = 6 - from - to;

	if (diskNum == 1) {
		cout << "Move disk " << diskNum << " from " << from << " kern to " << to << " kern." << endl;
		num += 1;
	}
	else {
			hanoi(diskNum - 1, from, temp);
			cout << "Move disk " << diskNum << " from " << from << " kern to " << to << " kern." << endl;
			hanoi(diskNum - 1, temp, to);
			num += 1;
	}
}