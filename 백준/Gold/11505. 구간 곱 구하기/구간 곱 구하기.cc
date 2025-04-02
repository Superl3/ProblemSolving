#include<iostream>
#include<vector>

using namespace std;

class SegTree {
	vector<int> tree;
	vector<int> raw;
	int build(int node, int L, int R) {
		if (L == R) {
			tree[node-1] = raw[L];
			return tree[node-1];
		}
		int mid = (R - L) / 2 + L;

		int left_multiply = build(node * 2, L, mid);
		int right_multiply = build(node * 2 + 1, mid+1, R);
		tree[node-1] = ((long long)left_multiply * right_multiply) % 1000000007;
		return tree[node-1];
	}
	int query(int node, int L, int R, int start, int end) {
		if (end < L || start > R)
			return 1;
		if (start >= L && end <= R) {
			return tree[node - 1];
		}
		int mid = (end - start) / 2 + start;

		int left_multiply = query(node * 2, L, R, start, mid);
		int right_multiply = query(node * 2 + 1, L, R, mid + 1, end);

		return ((long long)left_multiply * right_multiply) % 1000000007;
	}
	void update(int node, int L, int R, int pos, int new_value) {
 		if (L == R && L == pos) {
			tree[node-1] = new_value;
			return;
		}

		int mid = (R - L) / 2 + L;

		if (L <= pos && pos <= mid)
			update(node * 2, L, mid, pos, new_value);
		int left_multiply = tree[node * 2-1];

		if (mid + 1 <= pos && pos <= R)
			update(node * 2+1, mid + 1, R, pos, new_value);
		int right_multiply = tree[node * 2+1-1];

		tree[node - 1] = ((long long)left_multiply * right_multiply) % 1000000007;
	}

public:
	SegTree(vector<int> input) : raw(input) {
		tree.resize(raw.size() * 4);
		build(1, 0, raw.size() - 1);
	}
	void update(int pos, int new_value) {
		update(1, 0, raw.size()-1, pos, new_value);
	}
	int query(int L, int R) {
		return query(1, L, R, 0, raw.size() - 1);
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> inputs(N);
	for(auto &input : inputs)
		cin >> input;
	SegTree segtree(inputs);

	for(int i = 0; i < M + K; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			segtree.update(b-1, c);
		if(a == 2)
			cout << segtree.query(b - 1, c - 1) << '\n';
	}
}
/*
12345678
3-7
1 8
1234 / 5678
12 / 34
1 * (3*4)
56 / 78
(5*6) / 7 / 8
*/