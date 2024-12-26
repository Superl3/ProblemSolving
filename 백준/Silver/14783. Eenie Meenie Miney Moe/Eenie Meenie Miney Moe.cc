#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int> arr(L);
	for (auto& item : arr)
		cin >> item;

	int list_index = 0;


	list<int> queue;
	for (int i = 1; i <= N; i++)
		queue.push_back(i);

	auto idx = queue.end();
	idx--;
	while (queue.size() > 1) {
		auto item = arr[list_index];
		item %= queue.size();
		for (int i = 0; i < item; i++) {
			idx++;
			if (idx == queue.end())
				idx = queue.begin();
		}
		idx = queue.erase(idx);
		if (idx == queue.begin())
			idx = queue.end();
		idx--;
		if (idx == queue.end())
			idx = queue.begin();
		list_index = (list_index + 1) % L;
	}
	cout << queue.front();
	return 0;
}