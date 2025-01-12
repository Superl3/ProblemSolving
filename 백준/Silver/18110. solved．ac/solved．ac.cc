#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &item : arr)
		cin >> item;
	sort(arr.begin(), arr.end());
	int cut = (float)n * 0.15 + 0.5;

	int result = 0;
	for (int i = cut; i < n - cut; i++) {
		result += arr[i];
	}
	if(n-(cut*2) != 0)
		result = (float)result / (n-cut*2) + 0.5;
	cout << result << endl;
	return 0;
}