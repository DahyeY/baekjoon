#include <iostream>
#include <cstring>
using namespace std;
//R, G, B 중 하나 색칠
//같은 색별로 구역(상하좌우 인접 시)
//적록색약 빨초, 파
//비색약 빨, 초, 파
//출력 : 비색약, 색약 구역 수

int n;
char arr[101][101];
bool visited[101][101] = { false };
int cnt = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!visited[nx][ny] && arr[x][y] == arr[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//비색약
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	//색약
	memset(visited, false, sizeof(visited));
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') 
				arr[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
