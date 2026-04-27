#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    // 같은 시간대 m명 당 서버 1대
    // n x m명 이상 (n + 1) x m명 미만이라면 최소 n대
    // k 시간 동안만 운영
    vector<int> server(24+k, 0);
    for(int t=0; t<24; t++){
        int p = players[t]; // 현재 사용자 수
        int s = server[t] + 1; // 현재 서버 수
        int available = s * m - 1; // 서버 수 에 따른 최대 사용자 수
        
        if(p <= available) continue;
        
        else{
            int add = (p - available - 1) / m + 1;
            answer += add;
            for (int i=0; i<k; i++){
                server[t+i] += add;
            }
        }
        
    }
    return answer;
}