#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct DP {
	int early = 0;
	int not_early = 0;
};

vector<DP> dp;
vector<vector<int>> graph;
vector<bool> visit;
void dfs(int cur) {
	visit[cur] = true;
	dp[cur].not_early = 0;
	dp[cur].early = 0;
	for (auto& child : graph[cur]) {
		if (visit[child]) continue;
		dfs(child);
		dp[cur].not_early += dp[child].early;
		if (dp[child].early < dp[child].not_early)
			dp[cur].early += dp[child].early;
		else
			dp[cur].early += dp[child].not_early;
	}
	dp[cur].early += 1;
}
/*
dp[cur][0] = sum of dp[child][1]
무조건 child가 1이여야 함
dp[cur][1] = sum of dp[child][0] + 1
child가 1이거나 0이거나 상관없음
*/

int main() {
	int N;
	cin >> N;

	dp.resize(N);
	graph.resize(N, vector<int>());
	visit.resize(N, false);
	for (int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1;
		v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	if (dp[0].early > dp[0].not_early)
		cout << dp[0].not_early;
	else
		cout << dp[0].early;
	return 0;
}