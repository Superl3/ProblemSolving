#include<iostream>
#include<string>

using namespace std;

bool check_harshad(int i) {
	string s = to_string(i);

	int digit_sum = 0;

	for (auto& digit : s)
		digit_sum += (digit - '0');

	return i % digit_sum == 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = n;; i++) {
		if (check_harshad(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}