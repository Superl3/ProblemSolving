#include<iostream>

#include<vector>

#include<algorithm>
#include<map>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	map<int, vector<int>> arr;
	map<int, int> index;
	vector<int> order(N);
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number >> order[i];
		if (arr.find(order[i]) == arr.end()) {
			arr[order[i]] = vector<int>();
			index[order[i]] = 0;
		}
		arr[order[i]].push_back(number);
	}

	for (auto& pair : arr) {
		sort(pair.second.begin(), pair.second.end());
	}

	bool Y = true;

	int before = 0;
	for (int i = 0; i < N; i++) {
		int current = arr[order[i]][index[order[i]]++];
		if (current < before) {
			Y = false;
			break;
		}
		before = current;
	}
	cout << (Y ? 'Y' : 'N') << endl;
	return 0;
}

/*
* 숫자와, 블럭 색을 입력받고, 모두 오름차순으로 가능한가?
* 그 말은, 같은 색끼리는 일단 모두 오름차순이여야 함.
*/