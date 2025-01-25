#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void erase_unique(vector<int>& vec) {
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

void count_item(const vector<int>& arr, vector<int>& countarr) {
	int idx = 0, cnt = 0, val = 0;

	auto iter = arr.cbegin(); 

	val = *iter;
	cnt = 1;

	iter ++;

	for (;iter != arr.cend();iter++) {
		if (val != *iter) {
			countarr[idx++] = cnt;
			val = *iter;
			cnt = 1;
		} else
			cnt += 1;
	}
	countarr[idx] = cnt;
}

int main() {
	int n;
	vector<int> A, B, C, D;
	vector<int> AA, BB;
	vector<int> AAcount, BBcount;

	cin >> n;
//	n = 4000;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
//		a = b = c = d = 0;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for (auto& a : A)
		for (auto& b : B)
			AA.push_back(-(a + b));
	for (auto& c : C)
		for (auto& d : D)
			BB.push_back(c + d);

	sort(AA.begin(), AA.end());
	sort(BB.begin(), BB.end());

	AAcount.resize(AA.size());
	BBcount.resize(BB.size());

	count_item(AA, AAcount);
	count_item(BB, BBcount);

	erase_unique(AA);
	erase_unique(BB);

	unsigned long long cnt = 0;
	for (auto aa = AA.begin(), bb = BB.begin(), aacnt = AAcount.begin(), bbcnt = BBcount.begin();;) {
		if ((*aa) == (*bb)) {
			cnt += (unsigned long long)(*aacnt) * (*bbcnt);
		}
		if (aa + 1 != AA.end() && bb + 1 != BB.end()) {
			if(*(aa+1) > *(bb+1)) {
				bb++;
				bbcnt++;
			}
			else {
				aa++;
				aacnt++;
			}
		} else if(aa + 1 != AA.end()) {
			aa++;
			aacnt++;
		}
		else if(bb + 1 != BB.end()) {
			bb++;
			bbcnt++;
		}
		else
			break;
	}

	cout << cnt << endl;
}