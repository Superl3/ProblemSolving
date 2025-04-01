#include<vector>
#include<iostream>

using namespace std;

struct minmax {
	int min = -1;
	int max = -1;

	void operator=(const int& val) {
		this->min = val;
		this->max = val;
	}
	bool operator==(const int& val) {
		return this->min == val && this->max == val;
	}

	static minmax LEFT(const vector<minmax>& tree, const int& node) {
		return tree[node * 2];
	}
	static minmax RIGHT(const vector<minmax>& tree, const int& node) {
		return tree[node * 2 + 1];
	}
};

class SegTree {
	vector<int> arr;
	vector<minmax> tree;
	int size;
	void build(int node, int start, int end) {
		if (start == end) {
			tree[node] = arr[start]; // 리프 노드에 원소 저장
		}
		else {
			int mid = (start + end) / 2;
			build(2 * node, start, mid);
			build(2 * node + 1, mid + 1, end);

			tree[node].min = minmax::LEFT(tree, node).min < minmax::RIGHT(tree, node).min ? 
				minmax::LEFT(tree, node).min : minmax::RIGHT(tree, node).min;
			tree[node].max = minmax::LEFT(tree, node).max > minmax::RIGHT(tree, node).max ? 
				minmax::LEFT(tree, node).max : minmax::RIGHT(tree, node).max;
		}
	}
	minmax query(int L, int R, int node, int start, int end) {
		//cout << L << ' ' << R << ' ' << node << ' ' << start << ' ' << end << '\n';
		if (R < start || end < L)
		{
			return { -1, -1 };
		}
		if (L <= start && end <= R) return tree[node]; // 범위 완전히 포함

		int mid = (start + end) / 2;
		auto left_minmax = query(L, R, 2 * node, start, mid);
		auto right_minmax = query(L, R, 2 * node + 1, mid + 1, end);

		minmax mm;
		if (left_minmax == -1)
			mm = right_minmax;
		else if (right_minmax == -1)
			mm = left_minmax;
		else {
			mm.min = left_minmax.min < right_minmax.min ? left_minmax.min : right_minmax.min;
			mm.max = left_minmax.max > right_minmax.max ? left_minmax.max : right_minmax.max;
		}
		return mm;
	}
public:
	SegTree(vector<int> input) : arr(input), size(input.size()) {
		tree.resize(4 * size);
		build(1, 0, size-1);
	}
	minmax query(int L, int R) {
		return query(L, R, 1, 0, size - 1);
	}
};

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> num(N);
	for (auto& item : num)
		cin >> item;

	SegTree st(num);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		auto res = st.query(a-1, b-1);
		cout << res.min << ' ' << res.max << '\n';
	}
	cout << endl;
}