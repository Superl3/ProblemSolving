#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, threshold;
	cin >> N >> threshold;

	vector<int> arr(N);
	for (auto& item : arr)
		cin >> item;
	
	int min_length = 0;

	int sum = 0;
	int start = 0;
	for (int end = 0; end < N;end++) {

		sum += arr[end];
		while (sum >= threshold) {
			if(min_length == 0 || min_length >= (end - start + 1)) {
				min_length = end - start + 1;
			}
			if (sum - arr[start] < threshold) break;
			sum -= arr[start++];
		}
	}
	cout << min_length << endl;
	return 0;
}