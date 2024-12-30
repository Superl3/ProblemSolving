#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

const int length = 9;

int main() {
	int n;
	cin >> n;

	vector<unsigned long long>fac(length);

	fac[0] = 1;
	for (int i =1; i < 9; i++) {
		fac[i] = (i + 1) * fac[i - 1];
	}

	for (int i = 0; i < n; i++) {

		list<char> avail_num;
		for (int j = 0; j < length; j++)
			avail_num.push_back(j + 'a');

		string input;
		cin >> input;

		long long ans = 0;
		for (int i = 1; i <= length; i++) {
			auto pos = avail_num.begin();
			for (int j = 0;;j++) {
				if (*pos == input[i-1]) {
					avail_num.erase(pos);
					break;
				}
				ans += fac[length - i - 1];
				pos++;
			}
		}
		cout << ans+1 << endl;

	}
	return 0;
}