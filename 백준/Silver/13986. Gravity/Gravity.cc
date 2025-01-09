#include<iostream>
#include<string>
#include<vector>

using namespace std;

const char OBSTACLE = '#';
const char APPLE = 'o';
const char EMPTY = '.';

bool canFall(const int& i, const int& j, const vector<vector<char>>& arr) {
	int n = arr.size();
	int m = arr[0].size();

	if (i + 1 < n && arr[i + 1][j] == EMPTY)
		return true;
	else
		return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	for (auto& line : arr)
		for (auto& item : line)
			cin >> item;
	while (true) {
		bool moved = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == APPLE && canFall(i, j, arr)) {
					arr[i][j] = EMPTY;
					arr[i + 1][j] = APPLE;
					moved = true;
				}
			}
		}

		if (!moved) break;
	}
	for (auto& line : arr) {
		for (auto& item : line)
			cout << item;
		cout << '\n';
	}
	return 0;
 }