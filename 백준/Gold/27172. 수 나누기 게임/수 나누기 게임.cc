#include<iostream>
#include<vector>
int num[1000001] = { 0, };
using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> card(N);

	int max = 0;

	for (int i = 0; i < N; i++) {
		cin >> card[i];
		num[card[i]] = i+1;
		if(max < card[i])
			max = card[i];
	}
	
	vector<int> score(N, 0);
	for (int i = 0; i < N; i++) {
		auto item = card[i];
		for (int j = 2; item * j <= max; j++) {
			if (num[item * j] != 0) {
				score[i]+=1;
				score[num[item*j]-1]-=1;
			}
		}
	}
	
	for(const auto &item : score)
		cout << item << ' ';
	return 0;
}
/*
나누어 떨어지면 -1점, 나누게 만들면 1점 획득
하나씩 계산하는건 불가능 NlogN까지 정도만 가능

수학적 특성을 활용하는 문제
1000000까지일때, 소수나 최소공배수, 최대공약수정도는 구할 수 있을지도
i가 j의 최소공배수가 j면 j는 -1 i는 +1인거지

반복적인 연산을 줄이려면
a, b, c가 있고 b % a = 0이라고 c % a = 0이라고 c % b = 0은 아님



*/