#include<iostream>
#include<vector>

using namespace std;

class SegTree {
	struct min_idx {
		int min;
		int idx;

		bool operator==(int val) const {
			return this->min == val;
		}
		bool operator<(const min_idx& other) const {
			return (this->min < other.min) || (this->min == other.min && this->idx < other.idx);
		}
	};

	vector<min_idx> tree;
	int size;

	void build(int node, int start, int end, vector<int> &input) {
		if (start == end) {
			tree[node - 1] = { input[start], start };
			return;
		}
		int mid = (end - start) / 2 + start;
		build(node*2, start, mid, input);
		build(node*2+1, mid + 1, end, input);

		if (tree[node * 2] < tree[node * 2-1]) {
			tree[node-1] = tree[node * 2];
		}
		else {
			tree[node-1] = tree[node * 2-1];
		}
	}

	min_idx query(int node, const int &L, const int &R, int start, int end) {
		int mid = (end - start) / 2 + start;
		if (L <= start && R >= end)
			return tree[node - 1];
		if (start == end)
			return tree[node - 1];
		/*
		start mid / mid+1 end
		시작점이 미드보다 작으면
		끝점이 미드+1보다 크면
		*/
		min_idx min = { -1, -1 };
		if (L <= mid) { // L, R이 주어진 조건, start가 R보다 작다는건 범위 외
			min_idx left_query = query(node * 2, L, R, start, mid);
			if (min == -1 || left_query < min)
				min = left_query;
		}	
		if (R >= mid+1) {
			min_idx right_query = query(node * 2 + 1, L, R, mid + 1, end);
			if (min == -1 || right_query < min)
				min = right_query;
		}
		return min;
	}

	void update(int node, int start, int end, const int& idx, const int& val) {
		if (start == end && start == idx) {
			tree[node - 1] = { val, idx };
			return;
		}
		min_idx min = { -1, -1 };

		int mid = (end - start) / 2 + start;
		if (idx <= mid && idx >= start)
			update(node * 2, start, mid, idx, val);
		if(idx <= end && idx >= mid+1)
			update(node * 2+1, mid+1, end, idx, val);

		if (tree[node * 2] < tree[node * 2 - 1]) {
			tree[node - 1] = tree[node * 2];
		}
		else {
			tree[node - 1] = tree[node * 2 - 1];
		}
	}

public:
	SegTree(vector<int>& input) {
		size = input.size();
		tree.resize(size * 4);
		build(1, 0, size - 1, input);
	}
	int query(int L, int R) {
		min_idx result = query(1, L, R, 0, size - 1);
		return result.idx;
	}
	void update(const int &idx, const int &val) {
		update(1, 0, size - 1, idx, val);
	}
};
int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> inputs(N);
	for (auto& input : inputs)
		cin >> input;

	SegTree segtree(inputs);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			int index, target;
			cin >> index >> target;
			segtree.update(index-1, target);
		}
		else if (c == 2) {
			int start, end;
			cin >> start >> end;
			cout << segtree.query(start-1, end-1)+1 << '\n';
		}
	}
}