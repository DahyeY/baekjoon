#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();

    for (string rq : requests) {
        char target = rq[0];

        if (rq.size() > 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == target) {
                        storage[i][j] = '.';
                    }
                }
            }
        }
        else {
            vector<vector<char>> board (n+2, vector<char>(m+2, '.'));
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    board[i+1][j+1] = storage[i][j];
                }
            }
            
            vector<vector<bool>> visited (n+2, vector<bool>(m+2, false));
            queue<pair<int,int>> q;
            
            // 첫 좌표 방문처리
            q.push({0,0});
            visited[0][0] = true;
            
            vector<pair<int,int>> remove;
            
            while(!q.empty()){
                auto [x, y] = q.front(); 
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if(nx<0||ny<0||nx>=n+2||ny>=m+2) continue;
                    if(visited[nx][ny]) continue;
                    
                    //공기칸이면 방문처리
                    if(board[nx][ny]=='.'){
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                    else if(board[nx][ny] == target) { // 타겟이면
                        remove.push_back({nx-1,ny-1});
                    }
                    
                }
            }
            
            for(auto[x,y]:remove){
                storage[x][y] = '.';
            }
            
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != '.') answer++;
        }
    }

    return answer;
}