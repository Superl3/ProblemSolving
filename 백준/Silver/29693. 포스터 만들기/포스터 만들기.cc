#include<iostream>
#include<vector>

#include<queue>
#include<map>

using namespace std;

struct point {
	int y;
	int x;

	point operator+(point& pnt){
		return { y + pnt.y, x + pnt.x };
	}
	point next(const int &Y, const int &X) {
		int width = (X-1) / 2;
		int pos = (y-1) * (width) + (x-1) + 1;
		return { pos / width+1, pos % width+1 };
	}
	bool is_end(const int& Y, const int& X) {
		return Y-1 == y && x == 1;
	}
	bool is_mid(const int& Y, const int& X) {
		if (X % 2 == 0) {
			return x == X / 2-1;
		}
		else {
			return x == X / 2;
		}
	}
};

bool OOB(const point &pnt, const int& Y, const int& X) {
	if (pnt.x >= 0 && pnt.y >= 0 && pnt.x < X && pnt.y < Y)
		return false;
	return true;
}

point fway[4] = { {0,1}, {1,0}, {0, -1}, {-1, 0} };

const char WHITE = 'W', BLUE = 'B', YELLOW = 'Y';

void traversal(const point start, const int& Y, const int& X, vector<vector<char>>& arr, vector<vector<int>>& visit, bool & white_nearby_yellow) {
	queue<point> search;
	search.push(start);

	if (arr[start.y][start.x] == WHITE)
		white_nearby_yellow = false;

	while (!search.empty()) {
		auto cur = search.front();
		search.pop();

		for (auto& way : fway) {
			auto next = cur + way;
			if (OOB(next, Y, X)) continue;

			if (arr[start.y][start.x] == WHITE && arr[next.y][next.x] == YELLOW)
				white_nearby_yellow = true;

			if (visit[next.y][next.x] != 0 || arr[start.y][start.x] != arr[next.y][next.x])  continue;
			visit[next.y][next.x] = 1;
			search.push(next);
		}
	}
}

bool check(const int &Y, const int &X, vector<vector<char>> &arr) {
	
	map<char, int> area_count;
	area_count[WHITE] = 0;
	area_count[BLUE] = 0;
	area_count[YELLOW] = 0;

	bool white_nearby_yellow = true;

	vector<vector<int>> visit(Y, vector<int>(X, 0));
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (visit[y][x] == 0) {
				traversal({ y, x }, Y, X, arr, visit, white_nearby_yellow);
				area_count[arr[y][x]] += 1;
				if (!white_nearby_yellow) break;
			}
		}
		if (!white_nearby_yellow) break;
	}

	//cout << "AREA_WHITE: " << area_count[WHITE] << ", AREA_BLUE: " << area_count[BLUE] << ", AREA_YELLOW: " << area_count[YELLOW] << endl;
	//cout << "white_nearby_yellow: " << (white_nearby_yellow ? "YES" : "NO") << endl;

	return white_nearby_yellow && area_count[WHITE] == 2 && area_count[BLUE] == 1 && area_count[YELLOW] == 1;
}

bool dfs(point cur, const int& Y, const int& X, vector<vector<char>>& arr) {
	while (arr[cur.y][cur.x] == BLUE) {
		if (cur.is_end(Y, X)) {
			//for (auto& row : arr) {
			//	for (auto& item : row)
			//		cout << item;
			//	cout << endl;
			//}
			//cout << endl;
			return check(Y, X, arr);
		}
		cur = cur.next(Y, X);
	}
	if (!cur.is_mid(Y, X)) {
		arr[cur.y][cur.x] = arr[cur.y][X - cur.x - 1] = WHITE;
		if (dfs(cur.next(Y, X), Y, X, arr)) return true;
	}
	arr[cur.y][cur.x] = arr[cur.y][X - cur.x - 1] = BLUE;
	if (dfs(cur.next(Y, X), Y, X, arr)) return true;
	arr[cur.y][cur.x] = arr[cur.y][X - cur.x - 1] = YELLOW;
	if (dfs(cur.next(Y, X), Y, X, arr)) return true;
	return false;
}

int main() {
	int Y, X;
	cin >> Y >> X;	

	vector<vector<char>> arr(Y, vector<char>(X));
	for (auto& row : arr)
		for (auto& item : row)
			cin >> item;

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < (int)(X / 2); j++) {
			if (arr[i][j] != arr[i][X - j - 1])
			{
				if (arr[i][j] == WHITE && arr[i][X - j - 1] == BLUE)
					arr[i][j] = BLUE;
				else if (arr[i][j] == BLUE && arr[i][X - j - 1] == WHITE)
					arr[i][X - j - 1] = BLUE;
			}
		}
	}

	bool result = dfs({ 1,1 }, Y, X, arr);
	cout << (result ? "YES" : "NO") << endl;
	if (result) {
		for (auto& row : arr) {
			for (auto& item : row)
				cout << item;
			cout << endl;
		}
	}
	return 0;
}

/*
경우의 수
1. 왼쪽이 W, 오른쪽이 W
2. 왼쪽이 W, 오른쪽이 B
- 왼쪽이 무조건 B가 되어야 함
3. 왼쪽이 B, 오른쪽이 W
- 오른쪽이 무조건 B가 되어야 함
4. 왼쪽이 B, 오른쪽이 B

노란색이 흰색 사이에만 있으면 되는거지

대칭으로 다 채운 후에
BFS 서치를 하여 이어주는 그림을 찾는다
*/