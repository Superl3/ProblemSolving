#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<string> data(3);
	for (auto& item : data)
		cin >> item;
	int num = 0;
	for (auto& item : data) { 
		if (item[0] >= '0' && item[0] <= '9') {
			num = stoi(item) + (3-num);
			break;
		}
		num += 1;
	}
	if (num % 15 == 0)
		cout << "FizzBuzz";
	else if (num % 3 == 0)
		cout << "Fizz";
	else if (num % 5 == 0)
		cout << "Buzz";
	else
		cout << num;
}