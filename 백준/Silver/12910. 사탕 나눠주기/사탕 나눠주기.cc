#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	map<int, int> map;
	for (auto& item : arr) {
		cin >> item;
		
		if (map.find(item) == map.end())
			map[item] = 0;
		map[item]+=1;
	}

	int result = 0;
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for (int k = 1; k <= n; k++) {
		dp[k] = dp[k - 1] * map[k];
		result += dp[k];
	}

	cout << result;
	return 0;
}

/*
* 1 2 3 4 4 5 5 7
* 1 2 3
* 1 2 3 4 4 5 5
* 1 + 1 + 1 + 1*2 + 1*2*2
*/