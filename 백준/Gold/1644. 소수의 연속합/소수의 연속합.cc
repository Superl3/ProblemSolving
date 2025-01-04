#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> getPrimeArr(const int& limit) {
	vector<bool> isPrime(limit + 1, true);
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(limit); i++) {
		if (isPrime[i] == false) continue;
		for (int j = i; i * j <= limit; j+=1) {
			isPrime[j*i] = false;
		}
	}
	vector<int> result;
	for (int i = 1; i <= limit; i++) {
		if (isPrime[i])
			result.push_back(i);
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	auto prime_arr = getPrimeArr(n);
	int start = 0, end = 0, count = 0;
	long long sum = 0;

	while (true) {
		if (sum >= n) {
			sum -= prime_arr[start++];
		}
		else if (end == prime_arr.size()) {
			break;
		}
		else {
			sum += prime_arr[end++];
		}
		if (sum == n) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}

/*
소수가 주어진다고 했을 때,
한 자연수가 주어지면 이 자연수를 연속된 소수로 표현하는 경우의 수를 어떻게 계산해야 할까?

*/