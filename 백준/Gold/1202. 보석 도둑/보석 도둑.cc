#include<iostream>
#include<vector>

#include<queue>

#include<algorithm>

using namespace std;

struct Gem {
	int weight, value;
	bool operator< (const Gem& other) const {
		return this->weight < other.weight;
	}
};

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<Gem> gems(N);
	for (auto& gem : gems)
		cin >> gem.weight >> gem.value;
	sort(gems.begin(), gems.end());

	vector<int> capacities(K);
	for (auto& capacity : capacities)
		cin >> capacity;
	sort(capacities.begin(), capacities.end());

	unsigned long long result = 0;

	priority_queue<int> pq_gems;
	int idx_gem = 0;
	for (auto &bag : capacities) {
		for (; idx_gem < N && gems[idx_gem].weight <= bag; idx_gem++) {
			pq_gems.push(gems[idx_gem].value);
		} // 크기순으로 정렬한 가방에서 현재 가방보다 가벼운 보석들 (넣기가능)을 큐에 보관
		
		if(!pq_gems.empty()) {
			result += pq_gems.top();
			pq_gems.pop();
		}
	}
	cout << result;
}