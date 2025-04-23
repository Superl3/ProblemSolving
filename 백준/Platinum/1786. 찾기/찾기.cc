#include <iostream>
#include <vector>
#include <string>

using namespace std;

// KMP 알고리즘의 접두사 함수 (pi 또는 LPS 배열)를 계산하는 함수
vector<int> compute_prefix_function(const string& P) {
    int m = P.length();
    vector<int> pi(m);
    pi[0] = 0; // pi[0]는 항상 0

    int length = 0; // 이전까지 일치한 접두사-접미사의 길이
    for (int i = 1; i < m; i++) {
        // 불일치가 발생하면 length를 pi[length-1] 값으로 줄여서
        // 더 짧은 접두사-접미사를 시도합니다.
        while (length > 0 && P[i] != P[length]) {
            length = pi[length - 1];
        }

        // 문자가 일치하면 length를 증가시킵니다.
        if (P[i] == P[length]) {
            length++;
        }

        // 현재 인덱스 i에서의 접두사-접미사 길이를 저장합니다.
        pi[i] = length;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // 입출력 속도 향상

    string T, P;
    getline(cin, T);
    getline(cin, P);

    // 패턴의 접두사 함수 계산
    vector<int> pi = compute_prefix_function(P);

    vector<int> matches;

    int q = 0; // 텍스트와 현재까지 일치하는 패턴의 길이 (패턴에서의 위치)
    for (int i = 0; i < T.length(); i++) { // 텍스트를 순회
        // 텍스트의 현재 문자 T[i]와 패턴의 현재 위치 P[q]를 비교
        // 불일치 시, 접두사 함수를 이용하여 q 값을 조정 (패턴 이동)
        while (q > 0 && T[i] != P[q]) {
            q = pi[q - 1];
        }

        // 문자가 일치하면 q 값을 증가시킵니다.
        if (T[i] == P[q]) {
            q++;
        }

        // q 값이 패턴의 길이와 같아지면 패턴을 찾은 것입니다.
        if (q == P.length()) {
            // 패턴이 시작하는 텍스트의 1-based 인덱스를 저장합니다.
            // 현재 i는 매칭된 마지막 문자의 인덱스(0-based)
            // 시작 인덱스(0-based) = i - P.length() + 1
            // 시작 인덱스(1-based) = (i - P.length() + 1) + 1 = i - P.length() + 2
            matches.push_back(i - P.length() + 2);

            // 다음 매칭을 찾기 위해 q 값을 접두사 함수 값을 이용하여 조정합니다.
            q = pi[q - 1];
        }
    }

    cout << matches.size() << '\n';
    for (int match_index : matches) {
        cout << match_index << '\n';
    }

    return 0;
}