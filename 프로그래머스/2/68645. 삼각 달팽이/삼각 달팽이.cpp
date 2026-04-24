#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> tri(n, vector<int>(n, 0));
    
    int x = 0, y = 0;
    int dir = 0;
    int num = 1;

    for (int i = 0; i < n; i++) {
        tri[i].resize(i + 1);
    }

    while (num <= n * (n + 1) / 2) {
        tri[x][y] = num++;

        int nx = x + (dir == 0 ? 1 : dir == 1 ? 0 : -1);
        int ny = y + (dir == 0 ? 0 : dir == 1 ? 1 : -1);

        if (nx < 0 || ny < 0 || nx >= n || ny > nx || tri[nx][ny] != 0) {
            dir = (dir + 1) % 3;
            nx = x + (dir == 0 ? 1 : dir == 1 ? 0 : -1);
            ny = y + (dir == 0 ? 0 : dir == 1 ? 1 : -1);
        }

        x = nx;
        y = ny;
    }

    vector<int> answer;
    for (auto row : tri)
        for (int v : row)
            if (v != 0) answer.push_back(v);

    return answer;
}