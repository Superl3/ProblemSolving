#include<iostream>

#include <vector>
using namespace std;

#include <stack>

const int max_try = 5;

vector<vector<int>> move_left(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int new_pos = 0, prev = -1;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 0) continue;
			if (prev == -1)
				prev = arr[i][j];
			else if (prev == arr[i][j]) {
				arr[i][new_pos++] = prev * 2;
				prev = -1;
			}
			else {
				arr[i][new_pos++] = prev;
				prev = arr[i][j];
			}
		}
		if (prev != -1)
			arr[i][new_pos++] = prev;
		for (int j = new_pos; j < arr[i].size(); j++)
			arr[i][j] = 0;
	}
	return arr;
}

vector<vector<int>> move_right(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int new_pos = arr[i].size() - 1, prev = -1;
		for (int j = arr[i].size() - 1; j >= 0; j--) {
			if (arr[i][j] == 0) continue;
			if (prev == -1)
				prev = arr[i][j];
			else if (prev == arr[i][j]) {
				arr[i][new_pos--] = prev * 2;
				prev = -1;
			}
			else {
				arr[i][new_pos--] = prev;
				prev = arr[i][j];
			}
		}
		if (prev != -1)
			arr[i][new_pos--] = prev;
		for (int j = new_pos; j >= 0; j--)
			arr[i][j] = 0;
	}

	return arr;
}

vector<vector<int>> move_up(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int new_pos = 0, prev = -1;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[j][i] == 0) continue;
			if (prev == -1)
				prev = arr[j][i];
			else if (prev == arr[j][i]) {
				arr[new_pos++][i] = prev * 2;
				prev = -1;
			}
			else {
				arr[new_pos++][i] = prev;
				prev = arr[j][i];
			}
		}
		if (prev != -1)
			arr[new_pos++][i] = prev;
		for (int j = new_pos; j < arr[i].size(); j++)
			arr[j][i] = 0;
	}

	return arr;
}

vector<vector<int>> move_down(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int new_pos = arr[i].size() - 1, prev = -1;
		for (int j = arr[i].size() - 1; j >= 0; j--) {
			if (arr[j][i] == 0) continue;
			if (prev == -1)
				prev = arr[j][i];
			else if (prev == arr[j][i]) {
				arr[new_pos--][i] = prev * 2;
				prev = -1;
			}
			else {
				arr[new_pos--][i]= prev;
				prev = arr[j][i];
			}
		}
		if (prev != -1)
			arr[new_pos--][i] = prev;
		for (int j = new_pos; j >= 0; j--)
			arr[j][i] = 0;
	}

	return arr;
}

int get_max(const vector<vector<int>>& arr) {
	int max = 0;
	for (auto& line : arr) {
		for(auto &item : line)
			if ( max < item)
				max = item;
	}
	return max;
}

int dfs(int cur, vector<vector<int>> arr) {
	int max = 0;
	if (cur == max_try) {
		return get_max(arr);
	}
	vector<int> dfs_result;
	dfs_result.push_back(dfs(cur+1, move_left(arr)));
	dfs_result.push_back(dfs(cur+1, move_right(arr)));
	dfs_result.push_back(dfs(cur+1, move_up(arr)));
	dfs_result.push_back(dfs(cur+1, move_down(arr)));

	for(auto &item : dfs_result)
		if(max < item)
			max = item;

	return max;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (auto& line : arr)
		for (auto& item : line)
			cin >> item;
	cout << dfs(0, arr);
	return 0;
}

/*
특징 : 같은 숫자가 나오면 합쳐진다 0 2240 = 0 4 4 0
*/