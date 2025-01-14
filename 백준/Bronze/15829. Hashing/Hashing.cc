#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int M = 1234567891;

	unsigned long long r = 1, hash=0;
	for (auto& letter: str) {
		int num = letter - 'a' + 1;
		hash += (num * r) % M;
		r = (r * 31) % M;
	}
	cout << hash % M << endl;
	return 0;
}