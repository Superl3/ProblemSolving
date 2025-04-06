#include<iostream>
#include<vector>

using namespace std;


#include<queue>
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

/*
DFS를 돌면서 결국 꼬리잡기를 하기 떄문에 어디서 시작하나 싸이클은 발생
1 2 3 

싸이클이 발생했을 경우, depth 순으로 카운팅을 하는데, 
*/
/*
inputs가 주어졌을 떄, 상호 참조의 경우에만 그룹이 짜여진다
그냥 구현하면 되는거 아닐까? 왜 난이도가 높지?
n의 수는 10만.

n^2으로 주어진대로 전부 탐색하면 당연 불가.
union-find와 같은 방법으로 가능할까?

1.
머리가 열려있으면 가능성이 존재
머리가 막혀있으면 가능성이 없음

막힐 경우에는 해당 학생들은 다른 팀에 속할 가능성은 없다.

1->3, 3->4, 4->3이면 4는 왕따
탐색을 했을 떄, 이 싸이클떄문인지, 다른게 이미 점령했는지 중요함

2->1->3->4->3
이미 셀프 꼬리를 잡았는데, 나를 follow한 사람이 없다? : 나가리
싸이클이 발생한 부분만 딱 잘라다 팀으로 만들면 된다

*/

int main() {
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