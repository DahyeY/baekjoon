#include <string>
#include <vector>
#include <iostream>
using namespace std;

// n번째 단계, 구간 [l, r]에서 1의 개수를 세는 함수
long long countOnes(int n, long long l, long long r) {
    if (n == 0) return 1; // 가장 작은 단위는 "1"

    long long len = 1;
    for (int i = 0; i < n; i++) len *= 5; // 현재 단계 전체 길이

    long long blockSize = len / 5; // 블록 하나의 길이
    long long cnt = 0;

    // 5개 블록: 0,1,2,3,4
    // 0: 1블록, 1: 1블록, 2: 0블록, 3: 1블록, 4: 1블록
    int pattern[5] = {1, 1, 0, 1, 1};

    for (int i = 0; i < 5; i++) {
        long long start = i * blockSize + 1;
        long long end = (i + 1) * blockSize;

        // 구간이 겹치지 않으면 스킵
        if (r < start || l > end) continue;

        // 구간이 완전히 포함된 경우
        if (l <= start && end <= r) {
            if (pattern[i] == 1) {
                cnt += countOnes(n - 1, 1, blockSize); // 1블록이면 세부 탐색
            }
            // 0블록이면 추가 안 함
        } else {
            // 일부만 겹치면 재귀적으로 더 탐색
            if (pattern[i] == 1) {
                cnt += countOnes(n - 1, max(1LL, l - start + 1), min(blockSize, r - start + 1));
            }
        }
    }
    return cnt;
}

int solution(int n, long long l, long long r) {
    return countOnes(n, l, r);
}

int main() {
    int n = 2;
    long long l = 4, r = 17;
    cout << solution(n, l, r) << endl;
    return 0;
}