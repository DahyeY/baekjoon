/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

int m, n; // m x n
int arr[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {0,0,-1,1}; //상하좌우
int dy[4] = {-1,1,0,0};

void tomato() {
    cin >> n >> m;
    
    for (int i =0;i <m;i++){
        for(int j = 0; j<n ; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx <m && ny >=0 && ny <n && arr[nx][ny] == 0){
                arr[nx][ny] = arr[x][y] + 1; //날짜 하루 더해서 저장
                q.push(make_pair(nx,ny));
                
//                for (int i =0;i <m;i++){
//                    for(int j = 0; j<n; j++){
//                        cout << arr[i][j] << "  ";
//                    }
//                    cout << endl;
//                }
//                cout << endl << endl << endl;
            }
        }
    }
}

int main(){
    tomato();
    bfs();
    
    int max = 0;
    for (int i = 0; i<m; i++){
        for(int j = 0; j< n;j++){
            if(arr[i][j]==0){
                cout << -1 << endl;
                return 0;
            }
            
            if (max<arr[i][j]) max = arr[i][j];
        }
    }
    
    cout << max - 1 << endl;
    
    return 0;
}
