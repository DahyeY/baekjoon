#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int M = triangle.size();
    int N = triangle[M-1].size();
    
    int dp[M][N];
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i<M; i++){
        int len = triangle[i].size()-1;
        
        dp[i][0] = dp[i-1][0]+triangle[i][0];
        dp[i][len] = dp[i-1][len-1]+triangle[i][len];
    }
    
    for(int i=1; i<M; i++){
        int len = triangle[i].size();
        
        for(int j=1; j<len-1; j++){
            
            dp[i][j] = max(dp[i-1][j]+triangle[i][j], dp[i-1][j-1]+triangle[i][j]);
        }
    }
    
    for(int i=0; i<N; i++){
        answer=max(answer,dp[M-1][i]);
    }
    
    return answer;
}