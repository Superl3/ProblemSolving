#include<vector>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct IDX {
	int b_idx = -1;
	int a_idx = -1;
};

int main() {
	string A, B;
	cin >> A >> B;

	vector<vector<int>> dp(1, vector<int>(A.size()));
	vector<vector<IDX>> dp_idx(1, vector<IDX>(A.size()));
	for (int b_i = 0; b_i < B.length(); b_i++) {
		auto b = B[b_i];

		int longest = 0;
		int long_idx = -1;
		vector<int> cur_dp(A.size());
		vector<IDX> cur_dpidx(A.size());
		for (int a_i = 0; a_i < A.length(); a_i++) {
			auto a = A[a_i];
			if (b == a) {
				cur_dp[a_i] = longest + 1;
				if (long_idx != -1)
					cur_dpidx[a_i] = { b_i, long_idx };
				else
					cur_dpidx[a_i] = { b_i, long_idx };
			}
			else {
				cur_dp[a_i] = dp[b_i][a_i];
				cur_dpidx[a_i] = dp_idx[b_i][a_i];
			}
			if (dp[b_i][a_i] > longest) {
				longest = dp[b_i][a_i];
				long_idx = a_i;
			}
		}
		dp.push_back(cur_dp);
		dp_idx.push_back(cur_dpidx);

	}

	int longest = 0;
	int long_idx = -1;
	for (int i = 0; i < A.length(); i++) {
		if (longest < dp[B.length()][i]) {
			longest = dp[B.length()][i];
			long_idx = i;
		}
	}

	cout << longest;
	if (longest > 0) {
		cout << '\n';
		IDX cur_idx = { B.length(), long_idx };
		stack<char> result;
		//result.push(A[long_idx]);
		while (true) {
			cur_idx = dp_idx[cur_idx.b_idx][cur_idx.a_idx];
			result.push(B[cur_idx.b_idx]);
			if (cur_idx.a_idx == -1) break;
		}
		while (!result.empty()) {
			cout << result.top();
			result.pop();
		}
	}
	return 0;
}

/*
dp는, 이전 b 인덱스에서 최고의 값을 찾아서 해당 값 + 1을 넣어줌
그렇게 하면, a 인덱스의 위치는 기록이 가능함

문제는, a 인덱스의 값이 그 이후의 값으로 오염될 가능성이 있다.
현재로써 제일 확실한 방법은, 최적의 a 인덱스가 갱신될 때의 b의 위치를 알아내는 것
그러니까 dp[i]가 업데이트 될 때, 해당 dp[i]값을 가져온 b와 a의 인덱스의 조합을 알아낼 수 있으면 성공

마지막 max에서 b_i a_i를 가져와서
b_i를 stack에 넣어주고, 저렇게 순차적으로 업데이트 하면 될듯 함

그렇다면 b_i를 어떻게 얻어올 수 있냐가 핵심
이전값의 a_i는 가져올 수 있는데, b_i를 어떻게 가져오지?

해당 방식으로 작성하면, 뿌리는 찾을 수 있음. 근데 뿌리를 찾고 싶은게 아니라, 바로 전 값을 찾고 싶은것. 근데 애초에 이전 값을 찾는 방식은 뿌리밖에 못찾음
이 뿌리와 끝값으로는 복원은 불가능


*/