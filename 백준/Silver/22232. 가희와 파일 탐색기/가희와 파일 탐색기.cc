#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

#include<algorithm>
using namespace std;

struct ext_type {
	vector<string> known_type;
	vector<string> unknown_type;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> input(n);
	map<string, ext_type> explorer;
	for (auto& item : input)
		cin >> item;
	set<string> known_extension;
	for (int i = 0; i < m; i++) {
		string item;
		cin >> item;
		known_extension.insert(item);
	}

	for (auto& str : input) {

		auto pos = str.find('.');
		string filename = str.substr(0, pos);
		string extension = str.substr(pos + 1);

		if (explorer.count(filename) == 0)
			explorer[filename] = ext_type{ {}, {} };

		if (known_extension.count(extension) > 0)
			explorer[filename].known_type.push_back(extension);
		else
			explorer[filename].unknown_type.push_back(extension);
	}

	for (auto& file_pair : explorer) {
		sort(file_pair.second.known_type.begin(), file_pair.second.known_type.end());
		for (auto& item : file_pair.second.known_type)
			cout << file_pair.first << '.' << item << '\n';
		sort(file_pair.second.unknown_type.begin(), file_pair.second.unknown_type.end());
		for (auto& item : file_pair.second.unknown_type)
			cout << file_pair.first << '.' << item << '\n';
	}
	return 0;
}