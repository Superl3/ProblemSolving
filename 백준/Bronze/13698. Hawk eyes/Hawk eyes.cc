#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int SIZE = 4;
const int SMALL_BALL = 1;
const int LARGE_BALL = 2;
const int EMPTY = 0;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swapCase(char &c, vector<int> &arr) {
	switch (c) {
	case 'A':
		swap(arr[0], arr[1]);
		break;
	case 'B':
		swap(arr[0], arr[2]);
		break;
	case 'C':
		swap(arr[0], arr[3]);
		break;
	case 'D':
		swap(arr[1], arr[2]);
		break;
	case 'E':
		swap(arr[1], arr[3]);
		break;
	case 'F':
		swap(arr[2], arr[3]);
		break;
	}
}

int main() {
	vector<int> arr(SIZE, EMPTY);
	arr[0] = SMALL_BALL;
	arr[SIZE - 1] = LARGE_BALL;

	string input;
	cin >> input;

	for (auto& item : input) {
		swapCase(item, arr);
	}

	int pos_SMALL_BALL = -1, pos_LARGE_BALL= -1;
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] == SMALL_BALL)
			pos_SMALL_BALL = i;
		else if (arr[i] == LARGE_BALL)
			pos_LARGE_BALL = i;
	}

	cout << pos_SMALL_BALL + 1 << '\n' << pos_LARGE_BALL+1;
	return 0;
}