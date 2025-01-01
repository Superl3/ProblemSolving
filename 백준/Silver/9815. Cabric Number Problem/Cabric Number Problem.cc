#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<math.h>
using namespace std;

vector<int> analyze_digit(int n) {
	vector<int> res;

	string str = to_string(n);
	for (auto& letter : str)
		res.push_back(letter - '0');
	
	return res;
}

int large(const vector<int>& nums) {
	int result = 0;

	int power = pow(10, nums.size()-1);
	for (int i = nums.size() - 1; i >= 0; i--) {
		result += nums[i] * power;
		power /= 10;
	}

	return result;
}
int small(const vector<int>& nums) {
	int result = 0;

	int power = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		result += nums[i] * power;
		power *= 10;
	}
	return result;
}

bool validation(int n) {
	string s = to_string(n);
	auto first_letter = s[0];

	bool not_same = false;
	for (auto& letter : s)
		if (first_letter != letter)
			not_same = true;

	return not_same && s.length() == 4;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == -1) break;

		cout << "N=" << n << ':' << endl;
		if (!validation(n)) {
			cout << "No!!" << endl;
			continue;
		}

		vector<int> larges, smalls;

		int cnt = 0;
		int num = n;
		while (true) {
			cnt += 1;
			auto nums = analyze_digit(num);
			sort(nums.begin(), nums.end());

			int l = large(nums);
			cout << l << '-';

			int s = small(nums);
			cout << s << '=';
			num = l - s;
			cout << num << endl;
			if (num == 6174 || num == 0) {
				cout << "Ok!! " << cnt << " times" << endl;
				break;
			}
		}
		
	}
	return 0;
}