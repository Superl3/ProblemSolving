#include<iostream>

#include<vector>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> memusages(N);
	for (auto& memusage : memusages)
		cin >> memusage;

	int cost_sum = 0;

	vector<int> quitcosts(N);
	for (auto& quitcost : quitcosts) {
		cin >> quitcost;
		cost_sum += quitcost;
	}

	vector<vector<int>>dp(N, vector<int>(cost_sum + 1, -1));
	for (int i = 0; i < N; i++) {
		dp[i][quitcosts[i]] = memusages[i];
		if(i > 0){
			for (int j = 0; j <= cost_sum; j++) {
				if(dp[i][j] < dp[i-1][j])
					dp[i][j] = dp[i - 1][j];
				if (j >= quitcosts[i] &&
					dp[i - 1][j - quitcosts[i]] != -1 && dp[i][j] < dp[i - 1][j - quitcosts[i]] + memusages[i])
					dp[i][j] = dp[i - 1][j - quitcosts[i]] + memusages[i];
			}
		}

		//for (int j = 0; j <= cost_sum; j++) {
		//	if (dp[i][j] != -1)
		//		cout << j << '\t';
		//}
		//cout << '\n';
		//for (int j = 0; j <= cost_sum; j++) {
		//	if (dp[i][j] != -1)
		//		cout << dp[i][j] << '\t';
		//}
		//cout << "\n\n";
	}
	for (int i = 0; i <= cost_sum; i++) {
		if (dp[N - 1][i] >= M) {
			cout << i;
			break;
		}
	}
	return 0;
}