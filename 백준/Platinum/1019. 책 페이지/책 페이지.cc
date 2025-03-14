#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

void calc(vector<unsigned long long>& result, vector<int> base, int length) {

	bool nobase = true;
	for (auto& digit : base) {
		if (digit > 0) {
			nobase = false;
			break;
		}
	}

	unsigned long long sum = 0;
	if (!nobase) {
		result[0] += pow(10, length - 1) * length;
	}
	else {
		for (int k = length; k >= 2; k--) {
			result[0] += pow(10, k - 2) * (k - 1) * 9;
		}
	}
	for (int i = 1; i <= 9; i++) {
		result[i] += pow(10, length - 1) * length;
	}
	for (int i = 0; i <= 9; i++) {
		if (length == 0)
			result[i] += base[i];
		else
			result[i] += base[i] * pow(10, length);
	}
}

int main() {
	string str;
	cin >> str;

	vector<unsigned long long> result(10, 0);
	vector<int> base(10, 0);
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str[i] - '0'; j++) {
			if (i != 0 || j != 0)
				base[j] += 1;
			calc(result, base, str.length() - i - 1);
			if (i != 0 || j != 0)
				base[j] -= 1;
		}
		base[str[i] - '0'] += 1;
	}
	calc(result, base, 0);
	for (auto& item : result)
		cout << item << ' ';
	return 0;
}