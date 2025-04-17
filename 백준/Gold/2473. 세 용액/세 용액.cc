#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<long long> liquids(N);
	for (auto& liquid : liquids)
		cin >> liquid;

	sort(liquids.begin(), liquids.end());

	long long min = 0;
	vector<int> minList;

	for (int i = 0; i < N - 2; i++) {
		long long mid = liquids[i] * -1;
		int start = i + 1;
		int end = N - 1;
		while (start < end) {
			long long cur = liquids[start] + liquids[end];
			if (minList.size() == 0 || min > abs(mid - cur)) {
				min = abs(mid - cur);
				minList.clear();
				minList.push_back(i);
				minList.push_back(start);
				minList.push_back(end);
			}
			if (abs(mid - (liquids[start + 1] + liquids[end])) > abs(mid - (liquids[start] + liquids[end - 1])))
				end -= 1;
			else
				start += 1;

		}
	}
	for (auto& val : minList)
		cout << liquids[val] << ' ';
	return 0;
}
/*
-24 -6 -3 -2 98 100 61

24
*/