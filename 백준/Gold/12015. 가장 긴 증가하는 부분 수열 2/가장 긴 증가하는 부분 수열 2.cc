#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> inputs(N);
	vector<int> tails;
	tails.reserve(N);
	for (auto& input : inputs) {
		cin >> input;

		auto it = lower_bound(tails.begin(), tails.end(), input);
		if (it == tails.end())
			tails.push_back(input);
		else
			*it = input;
	}
	cout << tails.size();
	
}