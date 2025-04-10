#include <iostream>
#include <vector>
#include <algorithm>
#include <stack> // stack 헤더 추가

using namespace std;

// long long 사용
typedef long long ll;

struct Point {
    ll x, y; // int -> ll

    bool operator<(const Point& p) const {
         return x < p.x || (x == p.x && y < p.y);
    }
};

// long long 반환 및 계산
ll ccw(const Point& O, const Point& A, const Point& B) {
    // 형변환 없이 ll로 바로 계산
    return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

stack<Point> lowerbound, upperbound;

int main() {

    ios_base::sync_with_stdio(false); // 입출력 속도 향상 (선택 사항)
    cin.tie(NULL);                   // 입출력 속도 향상 (선택 사항)

    int N;
    cin >> N;

    vector<Point> points(N);
    for (auto& p : points) cin >> p.x >> p.y;

    sort(points.begin(), points.end());

    // Lower Hull
    for (const auto& p : points) { 
        while (lowerbound.size() >= 2) {
            Point A = lowerbound.top();
            lowerbound.pop();
            Point O = lowerbound.top(); // 참조(&) 대신 값 복사

            if (ccw(O, A, p) > 0) { // 좌회전이면 A 유지
                lowerbound.push(A); // A를 다시 넣음
                break; // 현재 p를 처리하기 위해 내부 루프 탈출
            }
            // ccw <= 0 (우회전 또는 일직선) 이면 A는 pop된 상태 유지, 다음 루프 실행
        }
        lowerbound.push(p); // 현재 점 p를 스택에 추가
    }

    // Upper Hull
    for (int i = N - 1; i >= 0; --i) { // 역순으로 순회
        const auto& p = points[i];
        while (upperbound.size() >= 2) {
            Point A = upperbound.top();
            upperbound.pop();
            Point O = upperbound.top();

            if (ccw(O, A, p) > 0) {
                upperbound.push(A);
                break;
            }
        }
        upperbound.push(p);
    }

    cout << lowerbound.size() + upperbound.size() - 2 << "\n";

    return 0;
}