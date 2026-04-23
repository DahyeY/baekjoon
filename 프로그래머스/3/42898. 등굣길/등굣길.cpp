#include <string>
#include <vector>

using namespace std;
int cnt = 0;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // n x m , 물에 잠긴 거 puddles
    // 최단경로 % 1000000007 
    
    // 최단경로는 m C n-1 개 에서 물이 있는 경우 빼기. 
    // 오른쪽이나 아래쪽으로만 움직여. 재귀로 풀기. 
    
    
    int map[101][101] = {0};
    
    for(vector<int> a : puddles){
        map[a[0]][a[1]] = -1;
    }
    
    for(int i=1; i<=m; i++){
        if(map[i][1]==-1) break;
        map[i][1]=1;
    }
    for(int j=1; j<=n; j++){
        if(map[1][j]==-1) break;
        map[1][j]=1;
    }
    

    

    for (int i=2; i<=m; i++){
        for(int j=2; j<=n; j++){
            if(map[i][j]==-1){
                continue;
            }
            if(map[i-1][j] != -1){
                map[i][j] += map[i-1][j];
                map[i][j] %= 1000000007;
            }
            if(map[i][j-1] != -1){
                map[i][j] += map[i][j-1];
                map[i][j] %= 1000000007;
            }
        }
    }
    
    return map[m][n];
}