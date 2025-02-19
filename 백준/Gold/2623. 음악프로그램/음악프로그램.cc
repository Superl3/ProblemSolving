#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> singer(N);

	vector<int> phase(N, 0);
	vector<list<int>> singer_list(N, list<int>());

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		vector<int> sub_pd_order(n);
		for(auto &item : sub_pd_order)
			cin >> item;

		for(int j = 0 ; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				singer_list[sub_pd_order[j] - 1].push_back(sub_pd_order[k] - 1);
				phase[sub_pd_order[k] - 1] += 1;
			}
		}
	}

	queue<int> order;
	for (int idx = 0; idx < N; idx++) {
		if (phase[idx] == 0) {
			order.push(idx);
		}
	}

	vector<int> result;

	while (!order.empty()) {
		auto cur = order.front();
		result.push_back(cur);
		order.pop();
		for (const auto& singer : singer_list[cur]) {
			phase[singer] -= 1;
			if (phase[singer] == 0)
				order.push(singer);
		}
	}
	
	if(result.size() == N) {
		for (auto& item : result) {
			cout << item+1 << '\n';
		}
	}
	else {
		cout << 0;
	}

	return 0;
}