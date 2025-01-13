#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> booked(6);
	for (auto& size : booked)
		cin >> size;
	int T, P;
	cin >> T >> P;

	unsigned long long t_count = 0;
	for (auto& size : booked) {
		t_count += (size % T == 0) ? (size / T) : (size / T + 1);
	}
	cout << t_count << '\n';
	unsigned long long p_count = n / P;
	unsigned long long p_left = p_count ? n % P: n;
	cout << p_count << ' ' << p_left << endl;
}