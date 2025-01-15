#include<iostream>
#include<string>

using namespace std;
int main() {
	while (true) {
		string input;
		getline(cin, input);
		if (input == "ENDOFINPUT") break;

		getline(cin, input);
		for (auto& letter : input) {
			if (letter >= 'A' && letter <= 'Z')
				letter = (letter - 'A' + 26 - 5) % 26 + 'A';
		}
		cout << input << '\n';

		getline(cin, input);

	}
	return 0;
}