#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int range = 2 * w + 1;

    int prev = 0;

    for (int s : stations) {
        int left = s - w;
        int right = s + w;

        if (left > prev + 1) {
            int gap = left - (prev + 1);
            answer += (gap + range - 1) / range;
        }

        prev = right;
    }

    if (prev < n) {
        int gap = n - prev;
        answer += (gap + range - 1) / range;
    }

    return answer;
}