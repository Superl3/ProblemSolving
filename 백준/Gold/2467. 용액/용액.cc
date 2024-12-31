#include <iostream>
#include<set>
#include <cmath>
#include <algorithm>
#include<vector>

using namespace std;

int findCloestOpposite(vector<int>& arr, int item) {

    int target = -item;
    auto it = lower_bound(arr.begin(), arr.end(), target);

    // 경계값 처리
    if (it == arr.begin()) {
        if (*it == item)
            return *(it+1);
        else
            return *it;
    }
    else if (it == arr.end()) {
        if (*(it-1) == item)
            return *(it - 2);
        else
            return *(it-1);
    }
    else {
        int prev_val = *(it - 1);
        if (prev_val == item) {
            if (it - 1 == arr.begin())
                return *it;
            else
                prev_val = *(it - 2);
        }
        int next_val = *it;
        if (next_val == item) {
            if (it + 1 == arr.end())
                return prev_val;
            else
                next_val = *(it + 1);
        }
        return (abs(target - prev_val) <= abs(target - next_val)) ? prev_val : next_val;
    }


}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& item : arr) {
        cin >> item;
    }

    int mini = arr[0], minj = arr[n - 1];
    int min = abs(minj + mini);

    for (auto &item : arr) {
        int candidatej = findCloestOpposite(arr, item);
        if (min > abs(item + candidatej)) {
            mini = item;
            minj = candidatej;
            min = abs(minj + mini);
        }
    }

    cout << mini << ' ' << minj << endl;
    return 0;
}