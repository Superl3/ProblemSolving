#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<set<int>>> grid(3, vector<set<int>>(3, set<int>()));
vector<set<int>> row(9, set<int>());
vector<set<int>> col(9, set<int>());
vector<int> get_avail_num(int y, int x, const vector<vector<char>>& board) {
	vector<int> avail_num;
	for (int i = 1; i <= 9;i++) {
		if (grid[y / 3][x / 3].count(i) == 0) continue;
		if (row[y].count(i) == 0) continue;
		if (col[x].count(i) == 0) continue;
		avail_num.push_back(i);
	}
	return avail_num;
}

bool dfs(int y, int x, vector<vector<char>>& board) {
	int pos = y * 9 + x;
	if (pos == 9 * 9) {
		return true;
	}
	if (board[y][x] == '0') {
		auto avail_num = get_avail_num(y,x, board);

		for (auto &num : avail_num) {

			grid[y / 3][x / 3].erase(num);
			row[y].erase(num);
			col[x].erase(num);

			board[y][x] += num;
			if (dfs((pos + 1) / 9, (pos + 1) % 9, board)) return true;
			board[y][x] -= num;
			grid[y / 3][x / 3].insert(num);
			row[y].insert(num);
			col[x].insert(num);
		}
	}
	else {
		return dfs((pos + 1) / 9, (pos + 1) % 9, board);
	}
	return false;
}

int main() {
	vector<vector<char>> board(9, vector<char>(9));
	for (auto& line : board)
		for (auto& item : line)
			cin >> item;

	for (int i = 0; i < 9;i++) {
		for (int j = 1; j <= 9;j++) {
			grid[i / 3][i % 3].insert(j);
			row[i].insert(j);
			col[i].insert(j);
		}
	}

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (board[y][x] == '0') continue;

			grid[y / 3][x / 3].erase(board[y][x] - '0');
			row[y].erase(board[y][x] - '0');
			col[x].erase(board[y][x] - '0');
		}
	}

	dfs(0, 0, board);

	for (auto& line : board) {
		for (auto& item : line)
			cout << item;
		cout << endl;
	}
	return 0;
}