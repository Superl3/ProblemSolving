#include<iostream>
#include<vector>
using namespace std;

/*
한번 팰린드롬이 끊기면 그 이후로도 X
ABCBA가 팰린드롬이면 BCB도 팰린드롬임

DP[A][B] -> A에서 B까지 팰린드롬 여부?
근데 그러면 어떻게 단계적으로 학습 -> 단계를 길이로?

*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N);
	for(auto &item : arr)
		cin >> item;

	vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

	for (int length = arr.size() - 1; length >= 0; length--) {
		for (int start = 0; start + length < arr.size(); start++) {
			bool isP = true;
			int end = start + length;
			if (dp[start][end] != -1) continue;
			for (int i = 0; i < (length+1) / 2; i++) {
				if (arr[start + i] != arr[end - i]) {
					isP = false;
					break;
				}
			}
			dp[start][end] = isP;
	//		cout << start << '-' << end << " : " << (isP ? "True" : "False") << '\n';
			if (isP) {
				for (int i = 1; i < (length+1) / 2; i++) {
					dp[start + i][end - i] = isP;
	//				cout << start + i << '-' << end - i << " : " << (isP ? "True" : "False") << '\n';
				}
			}
		}
	}

	int M;
	cin >> M;
	for (int T = 0; T < M; T++) {
		int S,E;
		cin >> S >> E;
		cout << dp[S-1][E-1] << '\n';

		//cout << solve(arr, S, E) << '\n';
	}
	return 0;
}