#include<iostream>
#include<string>
using namespace std;

bool check_yujin(const int& n) {
	bool yujin = false;

	string s = to_string(n);
	for (int i = 0; i < s.size() - 1; i++) {
		unsigned long long multiplied_front = 1, multiplied_rear=1;
		for (int j = 0; j <= i; j++)
			multiplied_front *= (s[j] - '0');
		for (int j = i + 1; j < s.size(); j++) {
			multiplied_rear *= (s[j]-'0');
		}
		if (multiplied_front == multiplied_rear) {
			yujin = true;
			break;
		}
	}
	return yujin;
}

int main() {
	int n;
	cin >> n;
	if (check_yujin(n))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}