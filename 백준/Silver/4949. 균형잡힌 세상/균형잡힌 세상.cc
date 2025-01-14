#include<string>
#include<iostream>
#include<stack>
using namespace std;
int main() {
	while (true) {
		stack<char> balance;

		string str;
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.') break;

		bool is_balanced = true;
		for (auto& letter : str) {
			if (letter == '(' || letter == '[')
				balance.push(letter);
			else if (letter == ')' || letter == ']') {
				if (balance.empty()) {
					is_balanced = false;
					break;
				}
				auto prev_bracket = balance.top();
				if (letter == ')' && prev_bracket == '(')
					balance.pop();
				else if (letter == ']' && prev_bracket == '[')
					balance.pop();
				else {
					is_balanced = false;
					break;
				}
			}
		}
		if (!balance.empty())
			is_balanced = false;

		if (is_balanced)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}