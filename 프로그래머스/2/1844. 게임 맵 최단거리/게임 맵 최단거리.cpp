#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[101][101] = {0};

#define X first
#define Y second

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int, int>> q;
    
    vis[0][0] = 1;
    q.push({0, 0});
    
    pair<int, int> cur;
    pair<int, int> next;

    while(!q.empty()){
        
        cur.X = q.front().X;
        cur.Y = q.front().Y;
        q.pop();
        
        for(int i = 0; i<4; i++){
            next.X = cur.X + dx[i];
            next.Y = cur.Y + dy[i];
            
            if(next.X<0||next.Y<0||next.X>N-1||next.Y>M-1||vis[next.X][next.Y]!=0) 
                continue;
            if(maps[next.X][next.Y]==0) 
                continue;
            
            if(vis[next.X][next.Y]==0)
                vis[next.X][next.Y]=vis[cur.X][cur.Y]+1;
            else 
                vis[next.X][next.Y]=min(vis[cur.X][cur.Y]+1, vis[next.X][next.Y]);
            
            q.push({next.X, next.Y});
        }
    }
    if(vis[N-1][M-1])
        return vis[N-1][M-1];
    else return -1;
}