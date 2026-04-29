#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int bfs (int x, int y, vector<string> &room){
    queue<pair<int, int>> q;
    int dist[5][5];
    memset (dist, -1, sizeof(dist));
    
    
    q.push({x, y});
    dist[x][y] = 0;
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if(dist[x][y]>2) continue;
        if(room[x][y]=='X') continue;
        if(room[x][y]=='P' && dist[x][y]!=0 && dist[x][y]<=2) return 0;
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0||ny<0||nx>=5||ny>=5||dist[nx][ny]!=-1) continue;
            
            // 방문 처리
            dist[nx][ny] = dist[x][y]+1;
            q.push({nx, ny});
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // 맨해튼 거리 |r1 - r2| + |c1 - c2| > 2 
    // 파티션 있으면 ㄱㅊ
    // 빈테이블 있고 거리가 2이면 지키지 않음. 
    
    // 5개 대기실, 각 5x5
    for(auto room : places){
        int x = 0, y = 0;
        bool OK = true;
        
        for (int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(room[i][j] == 'P') {
                    if(!bfs(i, j, room)) { // 거리 0 이하면
                        answer.push_back(0);
                        OK = false;
                        break;
                    }
                }
            }
            if(!OK) break;
        }
        if(OK) answer.push_back(1);
        
    }
    return answer;
}