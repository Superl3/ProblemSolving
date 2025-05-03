#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class HeapTree {
	vector<int> data;

	void heapify_up(int index) {
		if (index == 1)
			return;

		int parent_index = index / 2;
		if (data[parent_index - 1] > data[index - 1]) {
			swap(data[parent_index - 1], data[index - 1]);
			heapify_up(parent_index);
		}
	}

	void heapify_down(int index) {
		int left_child = index * 2, right_child = index * 2 + 1;
		
		if (data.size() < left_child)
			return;

		int next_index = left_child;
		int bigger_child = data[left_child-1];

		if (data.size() >= right_child && data[right_child - 1] < bigger_child) {
			next_index = right_child;
			bigger_child = data[right_child - 1];
		}

		if (data[index - 1] > bigger_child) {
			swap(data[index - 1], data[next_index-1]);
			heapify_down(next_index);
		}
	}

public:
	HeapTree() {
	}

	void push(const int &input) {
		data.push_back(input);
		heapify_up(data.size());
	}
	int pop() {
	
		int minimum = 0;
		if (data.size() > 0) {
			minimum = data[0];

			data[0] = data[data.size() - 1];
			data.pop_back();
			heapify_down(1);
		}
		return minimum;
	}
};

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	HeapTree ht;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (input == 0)
			cout << ht.pop() << '\n';
		else
			ht.push(input);

	}
	return 0;
}