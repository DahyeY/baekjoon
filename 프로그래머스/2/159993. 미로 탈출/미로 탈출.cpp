#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<string>& maps, pair<int,int> start, char target) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(maps[x][y] == target) {
            return dist[x][y];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(maps[nx][ny] == 'X') continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1; 
}

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();

    pair<int,int> S, L;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j] == 'S') S = {i, j};
            if(maps[i][j] == 'L') L = {i, j};
        }
    }

    int d1 = bfs(maps, S, 'L');
    if(d1 == -1) return -1;

    int d2 = bfs(maps, L, 'E');
    if(d2 == -1) return -1;

    return d1 + d2;
}