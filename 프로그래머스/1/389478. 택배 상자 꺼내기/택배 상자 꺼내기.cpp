#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int h = n / w;
    int r = n % w;
    vector<int> map(w, h);

    if (h % 2 == 1) {
        for (int i = 0; i < r; i++) map[i]++;
    } else {
        for (int i = 0; i < r; i++) map[w - 1 - i]++;
    }

    int x = (num - 1) / w;                 // 행 번호 (0부터 시작)
    int y_temp = (num - 1) % w;      // 열 번호 (0부터 시작)
    int y;
    if (x % 2 == 1) y = y_temp;      // 홀수 행: 그대로
    else y = w - 1 - y_temp;         // 짝수 행: 반대로

    answer += map[y] - x;
    return answer;
}