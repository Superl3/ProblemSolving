#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish {
    int x, y;
};

int main() {
    int s, n;
    cin >> s >> n;

    s += 1;

    vector<Fish> fishes(n);
    for (int i = 0; i < n; i++) {
        cin >> fishes[i].x >> fishes[i].y;
    }

    int max_fish = 0;

    // 그물의 좌상단 모서리를 모든 가능한 위치에 대해 탐색
    for (int x_start = 1; x_start <= 100; x_start++) {
        for (int y_start = 1; y_start <= 100; y_start++) {
            int x_end = x_start + s - 1; // 그물의 오른쪽 하단 x좌표
            int y_end = y_start + s - 1; // 그물의 오른쪽 하단 y좌표

            int fish_count = 0;

            // 그물 범위 내 물고기 계산
            for (const auto& fish : fishes) {
                if (fish.x >= x_start && fish.x <= x_end &&
                    fish.y >= y_start && fish.y <= y_end) {
                    fish_count++;
                }
            }

            max_fish = max(max_fish, fish_count);
        }
    }

    cout << max_fish << endl;

    return 0;
}
