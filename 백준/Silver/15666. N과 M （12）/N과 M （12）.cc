#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;
#include<unordered_set>

#include<string>
unordered_set<string> seen;

string stringhasher(vector<int> generated) {
	string res = "";
	for (auto& item : generated)
		res += (to_string(item) + ' ');
	return res;
}

void dfs(int depth, int prev_index, vector<int> &generated, const int& limit, const vector<int>& arr) {
	if (depth == limit) {
		auto hash_generated = stringhasher(generated);
		if (seen.count(hash_generated) == 0) {

			seen.insert(hash_generated);
			for (auto& item : generated)
				cout << item << ' ';
			cout << '\n';
		}
		return;
	}
	for (int i = prev_index; i < arr.size(); i++) {
		generated.push_back(arr[i]);
		dfs(depth + 1, i, generated, limit, arr);
		generated.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<int> input_set;
	for(int i = 0 ; i < n;i++) {
		int item;
		cin >> item;
		input_set.insert(item);
	}
	vector<int> arr(input_set.begin(), input_set.end());
	vector<int> generated;
	dfs(0, 0, generated, m, arr);
	return 0;
}