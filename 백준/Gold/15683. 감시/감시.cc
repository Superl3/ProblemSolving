#include<iostream>

#include<vector>

struct CCTV {
	int Y, X;
	int dir;
	int type;
};

using namespace std;

bool nextperm(vector<CCTV>& cctvs) {
	int seed = 0;
	int dim = 1;
	for (int i = cctvs.size() - 1; i >= 0; i--) {
		auto& cctv = cctvs[i];
		switch (cctv.type) {
		case 2:
			seed += dim * cctv.dir;
			dim *= 2;
			break;

		case 5:
			break;

		default:
			seed += dim * cctv.dir;
			dim *= 4;
			break;

		}
	}
	seed += 1;
	if (seed == dim) return false;
	for (auto& cctv : cctvs) {
		switch (cctv.type) {
		case 2:
			dim /= 2;
			cctv.dir = seed / dim;
			seed %= dim;
			break;

		case 5:
			break;

		default:
			dim /= 4;
			cctv.dir = seed / dim;
			seed %= dim;
			break;

		}
	}
	return true;
}

/*
4*2*2
3 1 1

1 + 2 + 12 = 15 + 1 = 16

*/

int fways[4][2] = { {0,1}, {1,0 }, {0,-1}, {-1,0} };

bool oob(const int& Y, const int& X, const int& N, const int& M) {
	if (Y < 0 || X < 0 || Y >= N || X >= M)
		return true;
	else
		return false;
}

void sightcheck(const int& dir, vector<vector<bool>>& insight, const int& start_y, const int& start_x, vector<vector<int>>& office, const int& N, const int& M) {
	int y = start_y, x = start_x;
	while (true) {
		y += fways[dir][0];
		x += fways[dir][1];
		if (oob(y, x, N, M)) break;
		if (office[y][x] == 6) break;
		insight[y][x] = true;
	}
}

int main() {

	int N, M;
	cin >> N >> M;
	vector<vector<int>> office(N, vector<int>(M));

	vector<CCTV> cctvs;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6) {
				cctvs.push_back({ i, j, 0, office[i][j] });
			}
		}
	}

	int min = -1;
	do {
		vector<vector<bool>> insight(N, vector<bool>(M, false));
		int blindspot = 0;
		for (auto& cctv : cctvs) {
			//cout << cctv.dir << ' ';
			switch (cctv.type) {
			case 1:
				sightcheck(cctv.dir, insight, cctv.Y, cctv.X, office, N, M);
				break;
			case 2:
				sightcheck(cctv.dir, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 2) % 4, insight, cctv.Y, cctv.X, office, N, M);
				break;
			case 3:
				sightcheck(cctv.dir, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 1) % 4, insight, cctv.Y, cctv.X, office, N, M);
				break;
			case 4:
				sightcheck(cctv.dir, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 2) % 4, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 3) % 4, insight, cctv.Y, cctv.X, office, N, M);
				break;
			case 5:
				sightcheck(cctv.dir, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 1) % 4, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 2) % 4, insight, cctv.Y, cctv.X, office, N, M);
				sightcheck((cctv.dir + 3) % 4, insight, cctv.Y, cctv.X, office, N, M);
				break;
			}
		}
		//cout << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] != 0) continue;
				if (insight[i][j] == false) blindspot++;
			}
		}
		if (min == -1 || min > blindspot)
			min = blindspot;
	} while (nextperm(cctvs));

	cout << min;
	return 0;
}

/*
* 먼저 배치를 하고 검사를 해본다. 가능성의 경우?
* 8*8, 1-5개 4*2*4*4*1
* CCTV는 선배치가 되어있기 때문에, 방향을 적절하게 설정만 해주면 된다
* 배열을 하나 더 만들어서, Direcion을 보관하는 맵을 만든다
*
*
*/