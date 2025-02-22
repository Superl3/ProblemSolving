#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
	vector<int> parent;
	vector<int> rank;
	public:
	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n,1);
		for(int i = 0 ; i < n ; i++)
			parent[i] = i;
	}
	int findParent(int cur) {
		if(parent[cur] != cur)
			parent[cur] = findParent(parent[cur]);

		return parent[cur];
	}
	bool insert(const int& a, const int& b) {
		auto a_root = findParent(a);
		auto b_root = findParent(b);
		if(a_root == b_root) return false;
		if (rank[a_root] > rank[b_root]) {
			parent[b_root] = a_root;
		}
		else if (rank[a_root] < rank[b_root]) {
			parent[a_root] = b_root;
		}
		else {
			parent[b_root] = a_root;
			rank[a_root] += 1;
		}
		return true;
	}
};

int main() {
	int N,M, i = 0;
	cin >> N >> M;
	UnionFind uf(N);
	for (i = 0; i < M; i++) {
		int a, b;
	 	cin >> a >> b;
		if(!uf.insert(a,b)) break;
	}
	if(i == M)
		cout << 0;
	else
		cout << i+1;
	
	return 0;
}

/*
기존 트리에서 싸이클이 생기는지 알아보는 방법
ab 간선을 추가한다는 것은 점 하나를 추가하는게 아니라
a와 b를 잇고, parent를 재정의 하는것이야.
*/