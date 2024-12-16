#include<iostream>
#include<vector>

using namespace std;

const int variation = 3;

int main() {
	vector<unsigned long long> ppl(variation);
	vector<unsigned long long> ticket(variation);
	
	for (auto& item : ppl)
		cin >> item;

	for (auto& item : ticket)
		cin >> item;

	unsigned long long result = 0;

	for (int i = 0; i < variation; i++) {
		for (int j = 0; j < variation; j++) {
			if (ppl[j] >= ticket[j]) {
				result += ticket[j];

				ppl[j] -= ticket[j];
				ticket[j] -= ticket[j];
			}
			else if (ppl[j] <= ticket[j]) {
				result += ppl[j];

				ticket[j] -= ppl[j];
				ppl[j] -= ppl[j];
			}

			ticket[(j + 1) % variation] += int(ticket[j] / 3);
			ticket[j] = 0;
		}
	}
	cout << result;
	return 0;
}

/*
* 치킨 A 피자 B 햄버거 C
* 
치킨 3장 = 피자 1장
피자 3장 = 햄버거 1장
햄버거 3장 = 치킨 1장

4 0 0
0 70 4

*/