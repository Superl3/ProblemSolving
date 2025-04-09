#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

// 방향 판정 함수
int orientation(Point a, Point b, Point c) {
    long long cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross == 0) return 0;         // 일직선
    return (cross > 0) ? 1 : 2;       // 1: 반시계, 2: 시계
}

// 점 c가 선분 ab 위에 있는지 확인
bool onSegment(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// 선분 교차 판정
bool doIntersect(Point p1, Point p2, Point q1, Point q2) {
    int o1 = orientation(p1, p2, q1);
    int o2 = orientation(p1, p2, q2);
    int o3 = orientation(q1, q2, p1);
    int o4 = orientation(q1, q2, p2);

    // 일반적인 경우
    if (o1 != o2 && o3 != o4) return true;

    // 특수한 경우: 일직선 위에 있고 겹치는 경우
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, p2, q2)) return true;
    if (o3 == 0 && onSegment(q1, q2, p1)) return true;
    if (o4 == 0 && onSegment(q1, q2, p2)) return true;

    return false;
}

int main() {
    Point A1, A2;
    Point B1, B2;

    cin >> A1.x >> A1.y >> A2.x >> A2.y;
    cin >> B1.x >> B1.y >> B2.x >> B2.y;

    if (doIntersect(A1, A2, B1, B2)) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }

    return 0;
}
