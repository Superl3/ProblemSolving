#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

const int shark_id = 9;


struct point {
	int y, x;

	point operator+(point const& v)
	{
		int x = this->x + v.x;
		int y = this->y + v.y;
		return { y, x };
	}

	bool operator==(point const& v)
	{
		return this->x == v.x && this->y == v.y;
	}

};

inline bool operator<(const point& a, const point& b) {
	// x 좌표가 다르면 x 좌표를 기준으로 비교
	if (a.x != b.x) {
		return a.x < b.x;
	}
	// x 좌표가 같으면 y 좌표를 기준으로 비교
	return a.y < b.y;
}

struct point_dist {
	point pnt;
	int dist;
};

const point NOT_FOUND = { -1, -1 };
const int UNREACHABLE = -1;

point fways[4] = { {0,1},{1,0},{0,-1},{-1,0} };

map<int, set<point>> prey_list;

bool out_of_bound(const point &pnt, const int& N) {
	return pnt.y < 0 || pnt.x < 0 || pnt.y >= N || pnt.x >= N;
}

void set_fastest_distance(vector<point_dist> &targets, const point &shark_point, const int& N, const vector<vector<int>>& arr, const int& shark_size) {
	queue<point_dist> queue;
	queue.push({ shark_point, 0 });

	set<point> visit;
	visit.insert(shark_point);

	int set_dist_count = 0;

	while (!queue.empty()) {
		point_dist pd = queue.front();
		queue.pop();


		if (arr[pd.pnt.y][pd.pnt.x] > 0) {
			for (auto& target : targets) {
				if (target.dist != UNREACHABLE) continue; // already set
				if (target.pnt == pd.pnt) {
					target.dist = pd.dist;
					set_dist_count += 1;
					break;
				}
			}
			if(set_dist_count >= targets.size())
				break;
		}
		for (auto& way : fways) {
			point next_pnt = pd.pnt + way;
			if (out_of_bound(next_pnt, N)) continue;
			if (visit.find(next_pnt) != visit.end()) continue;
			if (arr[next_pnt.y][next_pnt.x] > shark_size) continue; 
			visit.insert(next_pnt);
			queue.push({ next_pnt, pd.dist + 1 });
		}
	}

}

point_dist find_prey(const point &shark_point, const int & N, const vector<vector<int>>& arr, const int& shark_size) 
{
	vector<point_dist> candidates;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] > 0 && arr[y][x] < shark_size)
				candidates.push_back({{ y,x }, UNREACHABLE});
		}
	}

	point_dist target = { { -1, -1 }, N * N };

	set_fastest_distance(candidates, shark_point, N, arr, shark_size);

	for (auto& candidate : candidates) {
		if (candidate.dist == UNREACHABLE) continue;
		if (target.dist > candidate.dist) {
			target = candidate;
		}
		else if (target.dist== candidate.dist) {
			if (target.pnt.y == candidate.pnt.y) {
				if (target.pnt.x > candidate.pnt.x) {
					target = candidate;
				}
			}
			else if (target.pnt.y > candidate.pnt.y) {
				target = candidate;
			}
		}
	}
	return target;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N));

	point shark_point;

	queue<point> queue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == shark_id) {
				shark_point = { i,j };
				//queue.push({ i,j });
				tmp = 0;
			}
			else if (tmp != 0) {
				if (prey_list.find(tmp) == prey_list.end())
					prey_list[tmp] = set<point>();
				prey_list[tmp].insert({ i,j });
			}
			arr[i][j] = tmp;
		}
	}

	int shark_size = 2;
	int answer = 0;

	int feed_count = 0;

	while (true) {
		point_dist next_prey = find_prey(shark_point, N, arr, shark_size);
		if (next_prey.pnt == NOT_FOUND) break;

		answer += next_prey.dist;
		feed_count += 1;
		if (feed_count >= shark_size) {
			feed_count = 0;
			shark_size += 1;
		}

		shark_point = next_prey.pnt;
		arr[shark_point.y][shark_point.x] = 0;

	}
	cout << answer;
	return 0;
}

/*
아기 상어의 크기는 2
작은 물고기 : 먹을 수 있음
같은 물고기 : 지나갈 수 있음
큰 물고기 : 못 지나가고 못 먹음
자기 크기만큼 먹을수록 크기가 1오름

1. 먹을 수 있는 물고기가 없으면 엄마 상어에게 도움
2. 먹을 수 있는 물고기가 1마리면 그 물고기로 이동
3. 먹을 수 있는 물고기가 여러마리면 가장 가까운 물고기
4. 거리가 가깝다면, 가장 위에 있는 물고기, 가장 왼쪽에 있는 물고기

*/