#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int TICKET_LEN = 6;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		set<int> lottery;
		for (int i = 1; i <= 49; i++)
			lottery.insert(i);

		for (int num = 0; num < n; num++) {
			for (int i = 0; i < TICKET_LEN; i++) {
				int tmp;
				cin >> tmp;
				if (lottery.find(tmp) != lottery.end())
					lottery.erase(tmp);
			}
		}

		if (lottery.size() == 0)
			cout << "Yes";
		else
			cout << "No";
		cout << '\n';
	}
	return 0;
}