#include<iostream>
#include<list>
using namespace std;
int main() {
	int n;
	cin >> n;
	int output = -1;
	list<int> data;
	for (int i = 1; i <= n; i++)
		data.push_back(i);
	while (!data.empty()) {
		output = data.front();
		data.pop_front();
		if (data.empty()) break;
		data.push_back(data.front());
		data.pop_front();
	}
	cout << output << endl;
	return 0;
}