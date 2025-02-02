#include<iostream>
#include<vector>
#include<algorithm>

struct cost_set {
	int start, end, cost;
	bool operator< (const cost_set& s) {
		return cost < s.cost;
	}
};

#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent; // 멤버 변수: 각 원소의 부모를 저장
    vector<int> rank;   // 멤버 변수: 각 트리의 랭크를 저장

public:
    // 생성자: size만큼의 원소를 초기화
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1); // 초기 랭크는 1
        for (int i = 0; i < size; i++) {
            parent[i] = i; // 초기화: 각 원소는 자기 자신을 가리킴
        }
    }

    // Find 연산: 경로 압축 적용
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]); // 경로 압축
        }
        return parent[x];
    }

    // Union 연산: 랭크 기반 합치기
    bool Union(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
        if (root_a == root_b) return false; // 이미 같은 집합

        // 랭크 기반 합치기
        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        }
        else if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        }
        else {
            parent[root_b] = root_a;
            rank[root_a] += 1;
        }
        return true;
    }
};
using namespace std;
int main() {
	int N,M;
	cin >> N >> M;
	vector<cost_set> cost_vector(M);
	for (auto& cs : cost_vector)
		cin >> cs.start >> cs.end >> cs.cost;

	sort(cost_vector.begin(), cost_vector.end());
	
	auto union_find = UnionFind(N);
	int cost = 0, max_mst_edge = -1;

	for (auto& cs : cost_vector) {
		if (union_find.Union(cs.start - 1, cs.end - 1)) {
			cost += cs.cost;
			max_mst_edge = cs.cost;
		}
	}
	cost -= max_mst_edge;
	cout << cost;
	return 0;
}

/*
일단 집들을 두개의 군으로 나눈다
그 후 집간의 한붓그래프가 되도록 구현한다

1. 집들을 두개의 군으로 나누는 것이 한붓 그래프에 변경을 일으키는가?
애초에 한붓그래프는 최소비용을 만들기 위한 방법이다

따라서 두개의 군으로 나누어 최소비용을 만드는게 과연 차이가 있을까?
최소비용을 만드는 방법론. : 최소 비용의 간선만을 하나씩 선택한다

두개의 서브그래프로 나누어 최소비용 그래프를 만드는것과
하나의 최소비용 그래프를 만든 후 서브그래프를 만드는것과 최적값이 다른가
*/