#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[land.size()][4];
    int idx = 0;
    
    for(int num : land[0]) {
        dp[0][idx++] = num;
    }
    
    for (int i = 1; i<land.size(); i++){
        for(int j=0; j<4; j++){
            int m = 0;
            
            for(int n = 0; n <4; n++){ //j와 다른 열 중 최댓값
                if(n != j){
                    m = max(m, dp[i-1][n]);
                }
            }
            dp[i][j] = m + land[i][j];
        }
    }
    
    for(int i = 0; i <4; i++){ // 가장 끝 행 최댓값
        answer = max(answer, dp[land.size()-1][i]);
    }
    return answer;
}