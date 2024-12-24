#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	int size = pow(2, n);

	vector<int> arr(size, 0);
	for (auto& item : arr)
		cin >> item;

	if (t % 2 == 1) {
		for (int i = size - 1; i >= 0; i--)
			cout << arr[i] << ' ';
	}
	else {
		for (int i = 0; i < size; i++)
			cout << arr[i] << ' ';
	}
	return 0;
}