#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> child;
vector<int> visit;

int dfs(int cur, unordered_map<int, vector<int>>& graph) {

	visit[cur] = 1;

	int cnt = 1; 
	for (auto& item : graph[cur]) {
		if (item == cur || visit[item]) continue;
		cnt += dfs(item, graph);
	}

	child[cur] = cnt;
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;
	unordered_map<int, vector<int>> graph;
	child.resize(N);
	visit.resize(N, 0);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (graph.count(a - 1) == 0)
			graph[a - 1] = vector<int>();
		if (graph.count(b - 1) == 0)
			graph[b - 1] = vector<int>();

		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	dfs(R-1, graph);

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;

		cout << child[q - 1] << '\n';
	}
	return 0;
}