#include<iostream>
#include<vector>
using namespace std;

int main() {
	while (true) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		c *= 100;
		d *= 100;
		int max = 0;
		for (int i = 1; i <= 100; i++) {
			if ((a * i <= c && b * i <= d) || (a * i <= d && b * i <= c)) {
				max = i;
			}
			else
				break;
		}
		cout << max << '%' << endl;
	}
	return 0;
}