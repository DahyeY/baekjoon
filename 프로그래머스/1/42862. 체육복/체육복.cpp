#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 학생별 체육복 현황 (0: 없음, 1: 있음, 2: 여벌 있음)
    vector<int> clothes(n+1, 1);

    // 여벌 체크
    for (int r : reserve) {
        clothes[r]++;
    }

    // 도난 체크
    for (int l : lost) {
        clothes[l]--;
    }

    // 앞번호 → 뒷번호 순으로 그리디하게 빌려주기
    for (int i = 1; i <= n; i++) {
        if (clothes[i] == 0) {  
            // 앞에서 빌려줄 수 있으면
            if (i > 1 && clothes[i-1] == 2) {
                clothes[i-1]--;
                clothes[i]++;
            }
            // 뒤에서 빌려줄 수 있으면
            else if (i < n && clothes[i+1] == 2) {
                clothes[i+1]--;
                clothes[i]++;
            }
        }
    }

    // 체육복 있는 학생 세기
    for (int i = 1; i <= n; i++) {
        if (clothes[i] > 0) answer++;
    }

    return answer;
}