#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
/*
CENTER / UP / LEFT / DOWN / RIGHT
*/

enum FootPos {
	CENTER = 0,
	UP,
	LEFT,
	DOWN,
	RIGHT
};

int calcEnergy(const int& target, FootPos prev_position) {
	FootPos target_position = (FootPos)target;
	if (target_position == prev_position) return 1;
	if (prev_position == FootPos::CENTER) {
		return 2;
	}
	if (prev_position == FootPos::LEFT) {
		if (target_position == FootPos::RIGHT)
			return 4;
		else
			return 3;
	}
	else if (prev_position == FootPos::RIGHT) {
		if (target_position == FootPos::LEFT)
			return 4;
		else
			return 3;
	}
	else if (prev_position == FootPos::UP) {
		if (target_position == FootPos::DOWN)
			return 4;
		else
			return 3;
	}
	else if (prev_position == FootPos::DOWN) {
		if (target_position == FootPos::UP)
			return 4;
		else
			return 3;
	}
}

int main() {
	vector<int> order;
	while (true) {
		int ord;
		cin >> ord;
		if (ord == 0) break;
		order.push_back(ord);
	}
	vector<unordered_map <int , int >> dp(order.size());
	dp[0][order[0] * 5] = calcEnergy(order[0], FootPos::CENTER);
	dp[0][order[0]] = calcEnergy(order[0], FootPos::CENTER);
	for (int t = 1; t < order.size(); t++) {
		int min = -1;
		auto LEFT = (FootPos)(order[t]);
		for (int footpos = 0; footpos < 5; footpos++) {
			auto RIGHT = (FootPos)footpos;
			if (LEFT == RIGHT) continue;

			int min = -1;
			for (int prevpos = 0; prevpos < 5; prevpos++) {
				auto prevLEFT = (FootPos)prevpos;
				if (dp[t - 1].count(prevLEFT*5 + RIGHT) == 0) continue;
				auto cost = dp[t - 1][prevLEFT * 5 + RIGHT] + calcEnergy(LEFT, prevLEFT);
				if (min == -1 || min > cost)
					min = cost;
			}
			if (min != -1)
				dp[t][LEFT*5 + RIGHT] = min;
		}

		auto RIGHT = (FootPos)(order[t]);
		for (int footpos = 0; footpos < 5; footpos++) {
			auto LEFT = (FootPos)footpos;
			if (LEFT == RIGHT) continue;

			int min = -1;
			for (int prevpos = 0; prevpos < 5; prevpos++) {
				auto prevRIGHT = (FootPos)prevpos;
				if (dp[t - 1].count(LEFT * 5 + prevRIGHT) == 0) continue;
				auto cost = dp[t - 1][LEFT*5 + prevRIGHT] + calcEnergy(RIGHT, prevRIGHT);
				if (min == -1 || min > cost)
					min = cost;
			}
			if (min != -1)
				dp[t][LEFT * 5 + RIGHT] = min;
		}
	}
	int min = -1;

	for (auto& item : dp[order.size() - 1]) {
		if (min == -1 || min > item.second)
			min = item.second;
	}
	cout << min;

	return 0;
}