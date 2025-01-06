#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

void dfs(int depth, int visit, vector<int> generated,const int& limit, const vector<int>& arr) {
	if (depth == limit) {
		for(const auto &item : generated)
			cout << item << ' ';
		cout << '\n';
		return;
}
	for (int i = 0; i < arr.size(); i++) {
		if(!(visit & (1 << i))) {
			generated.push_back(arr[i]);
			visit |= (1 << i);
			dfs(depth+1, visit, generated, limit, arr);
			visit &= ~(1 << i);
			generated.pop_back();
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>arr(n);
	for (auto& item : arr)
		cin >> item;
	sort(arr.begin(),arr.end());

	dfs(0, 0, {}, m, arr);
	return 0;
}