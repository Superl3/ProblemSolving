#include<iostream>
#include<string>

using namespace std;
int main() {
	while (true) {
		string str;
		cin >> str;

		if (str == "0") break;

		bool pelindrom = true;
		for (int i = 0; i < str.length() / 2; i++) {
			if (str[i] != str[str.length() - i - 1]) {
				pelindrom = false;
				break;
			}
		}
		
		if (pelindrom)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}