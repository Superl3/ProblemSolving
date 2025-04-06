#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int solve(const int& N, const vector<int>& inputs) {
	int result = 0;
	vector<int> team(N);
	vector<int> visit(N, 0);
	//for (int i = 0; i < N; i++)
	//	team[i] = i;
	
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		queue<int> q;
		int count = 1;
		visit[i] = count++;
		int cur = i;
		while (true) {
			q.push(cur);
			int next = inputs[cur]-1;
			if (visit[next] != 0) {
				if(visit[next] != -1)
					result += count - visit[next];
				break;
			}
			visit[next] = count++;
			cur = next;
		}
		while (!q.empty()) {
			visit[q.front()] = -1;
			q.pop();
		}
	}
	return N - result;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> inputs(N);
		for (auto& input : inputs)
			cin >> input;
		cout << solve(N, inputs) << '\n';
	}
	return 0;
}