#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, long long> patch;
int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	vector<long long> inputs(N), sum(N);
	for (int i = 0; i < N; i++) {
		cin >> inputs[i];
		sum[i] = inputs[i];
		if (i > 0)
			sum[i] += sum[i - 1];
	}
	for (int i = 0; i < M + K; i++) {
		int a, idx;
		long long c;
		cin >> a >> idx >> c;
		idx -= 1;
		if (a == 1) {
			patch[idx] = c - inputs[idx];
		}
		else {
			c -= 1;
			int end_idx = c;
			long long partial_sum = sum[end_idx];
			if (idx > 0)
				partial_sum -= sum[idx - 1];

			for (auto& p : patch) {
				if (p.first >= idx && p.first <= end_idx)
					partial_sum += p.second;
			}
			cout << partial_sum << '\n';
		}
	}
}

/*
원래는 1~i까지의 sum을 담은 배열을 별도로 만들어서 보관한다
그러나 j번째의 아이템을 변경하면 이를 그대로 적용할 수 없다.

가장 먼저 떠오르는 방법으로는,
수정값을 보관하여 sum 배열을 통해 구한 뒤 패치를 해 주는 것이다.

1 2 3 4 5
1 3 6 10 15

3, 3 -> 6
2~5
원래는 sum[5]-sum[1] = 14
그러나 sum[5]-sum[1] + 3 = 17

5, 5 -> 2
3~5
원래는 sum[5] - sum[2] = 15-3 = 12
그러나 12 +3-3 = 12

그렇다면 이를 빠르게 패치하는 방법?
근데 같은 위치가 재변경이 될 경우에는 dist를 보관하면 되지 않는다
*/