#include<iostream>

#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct Line {
	int start;
	int end;
};

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Line> inputs(N);
	for (auto& input : inputs) {
		cin >> input.start >> input.end;
	}
	int D;
	cin >> D;

	vector<pair<int, int>> events;
	for (auto& input : inputs) {
		if (input.start > input.end)
			swap(input.start, input.end);
		if (input.end - input.start > D) continue;

		events.push_back({ input.end - D, -1 });
		events.push_back({ input.start, 1 });
	}
	sort(events.begin(), events.end());

	int overlap_count = 0;
	int max_overlap_count = 0;
	for (auto& event : events) {
		overlap_count += event.second * -1;
		max_overlap_count = max(max_overlap_count, overlap_count);
	}
	cout << max_overlap_count;
	return 0;
}