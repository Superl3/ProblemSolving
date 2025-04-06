#include<iostream>
#include<vector>

using namespace std;

struct Array {
	int row;
	int column;
};
#include<list>
long long calc(const vector<int>& order, const vector<Array>& arrs) {
	long long result = 0;

	list<Array> arrList(arrs.begin(), arrs.end());
	for (auto& idx : order) {
		//for (auto& arr : arrList) {
		//	cout << "(" << arr.row << ", " << arr.column << ") ";
		//}
		//cout << ": " << result << '\n';
		auto iter = arrList.begin();
		for (int i = 0; i < idx; i++) {
			iter++;
		}
		auto val = *iter;
		iter = arrList.erase(iter);
		result += val.row * val.column * (*iter).column;
		(*iter).row = val.row;
	}
	return result;
}

long long min_mult = -1;

void solve(int depth, vector<int> order, const int& N, const vector<Array>& arrs) {
	if (depth == N-1) {
		auto val = calc(order, arrs);
		if (min_mult == -1 || min_mult > val)
			min_mult = val;
		return;
	}
	for (int i = 0; i < N - depth - 1; i++) {
		order.push_back(i);
		solve(depth + 1, order, N, arrs);
		order.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Array> arrays(N);
	for (auto& arr : arrays)
		cin >> arr.row >> arr.column;

	vector<vector<long long>>dp(N, vector<long long>(N, 0));
	for (int t = 1; t < N; t++) {
		for (int i = 0; i + t < N; i++) {
			long long min = -1;
			for (int j = i; j < i + t; j++) {
				long long dp_val = dp[i][j] + dp[j+1][i + t] + arrays[i].row * arrays[j].column * arrays[i+t].column;
				if (min == -1 || min > dp_val)
					min = dp_val;
			}
			dp[i][i + t] = min;
		}
	}
	
	/*
	5x3 3x2 / 2x4 4x3
	*/
	cout << dp[0][N-1];
}

/*
i부터 j까지의 최적을 구할 수 있을 것 같긴 해.
dp[i][j] = i부터 j까지의 최적을 구할 수 있다고 치면 어떻게 해야할까?

*/