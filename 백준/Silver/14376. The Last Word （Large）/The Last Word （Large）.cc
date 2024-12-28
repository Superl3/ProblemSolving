#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		deque<char> result;
		result.push_back(str[0]);
		for (int j = 1; j < str.length(); j++) {
			if (result.front() <= str[j])
				result.push_front(str[j]);
			else
				result.push_back(str[j]);
		}
		cout << "Case #" << i + 1 << ": ";
		while (!result.empty()) {
			cout << result.front();
			result.pop_front();
		}
		cout << endl;
	}
	return 0;
}