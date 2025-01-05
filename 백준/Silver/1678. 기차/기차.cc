#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct train {
	string name;
	int time;
	bool operator<(const train& t) {
		return time < t.time;
	}
};

int main() {
	int T, M, N;
	cin >> T >> M >> N;

	map<int, string> table;

	vector<train> trains;
	for (int i = 0; i < T; i++) {
		string name;
		cin >> name;

		vector<int> timetable;
		while (true) {
			int time;
			cin >> time;
			if (time == -1) break;
			trains.push_back({ name, time });
		}
	}
	sort(trains.begin(), trains.end());
	int time = M, cnt = 0;
	auto iter = trains.begin();
	while (true) {
		if (iter->time >= time) {
			time = iter->time+1;
			cnt += 1;
			if (cnt == N) break;
		}
		iter++;
		if (iter == trains.end()) {
			time = 0;
			iter = trains.begin();
		}
	}
	cout << iter->name;
}
/*
결국 패턴이 반복될 것 같음. 해당 패턴을 패턴의 길이만큼 N을 나눠서 하면 될듯
같은 시간에 같은 열차를 타는 순간 반복되는 것
*/