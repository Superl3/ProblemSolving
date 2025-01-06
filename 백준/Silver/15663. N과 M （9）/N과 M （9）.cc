#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

#include <functional> // hash
#include<unordered_set>

#include<string>
unordered_set<string> seen;

struct VectorHash {
	size_t operator()(const std::vector<int>& v) const {
		std::hash<int> hasher;
		size_t seed = v.size();
		for (int i : v) {
			seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
}hasher;

string stringhasher(vector<int> generated) {
	string res = "";
	for(auto &item : generated)
		res += (to_string(item) + ' ');
	return res;
}

void dfs(int depth, vector<int> generated, int visit, const int& limit, const vector<int>& arr) {
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
	for (int i = 0; i < arr.size(); i++) {
		if (visit & (1 << i)) continue;

		visit |= 1 << i;
		generated.push_back(arr[i]);
		dfs(depth + 1, generated, visit, limit, arr);
		generated.pop_back();
		visit &= ~(1 << i);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (auto& item : arr)
		cin >> item;
	sort(arr.begin(), arr.end());
	dfs(0, {}, 0, m, arr);
	return 0;
}