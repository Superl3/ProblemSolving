#include<iostream>

#include<vector>
#include<queue>

#include<list>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	queue<int> order;
	vector<int> phase(N, 0);
	vector<list<int>> tall_list(N, list<int>());
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		tall_list[a-1].push_back(b-1);
		phase[b-1]+=1;
	}
	for (int idx = 0 ; idx<N;idx++) {
		if (phase[idx] == 0) {
			order.push(idx);
		}
	}

	while (!order.empty()) {
		auto cur = order.front();
		cout << cur+1 << ' ';
		order.pop();
		for (const auto& tall : tall_list[cur]) {
			phase[tall] -= 1;
			if(phase[tall] == 0)
				order.push(tall);
		}
	}
	

	return 0;
}

/*
그래프 문제가 아닐까?
위상 정렬로 생각하면 어때?
큰 애가 서려면 앞에 모든 애들이 다 서있어야 한다

앞에 서 있는 애들이 없는 애들을 먼저 배치하고, 배치하는 과정에서 앞에 서 있는 애들이 없는 애들을 추가적으로 큐에 넣어서 배치한다
그러려면, 앞에 서 있는 애들을 배치하는 순간에, 그 그래프에 연결된 애들을 -1씩 해주어야 함
*/