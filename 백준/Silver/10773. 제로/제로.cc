#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int k;
	cin >> k;

	stack<int> q;
	for (int i = 0; i < k; i++) {
		int item;
		cin >> item;
		if (item == 0)
			q.pop();
		else
			q.push(item);
	}
	unsigned long long sum = 0;
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}
	cout << sum << endl;

	return 0;
}