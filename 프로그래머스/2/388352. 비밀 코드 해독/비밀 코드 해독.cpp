#include <string>
#include <vector>

using namespace std;

vector<int> set;
int answer = 0;

void dfs(int num, int &n, vector<vector<int>> &q, vector<int> &ans){
    if(set.size()==5){
        //q, ans 확인
        
        for(int i=0; i<q.size();i++){
            int cnt =0; 
            
            for(int a:q[i]){
                for(int b:set){
                    if(a==b) cnt++;
                }
            }
            if(ans[i] != cnt) break;
            if(i==q.size()-1) answer++;
        }
        return;
    }
    else { // 값 추가하기. 
        for(int i=num; i<=n; i++){
            set.push_back(i);
            dfs(i+1, n, q, ans);
            set.pop_back();
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    //1~n까지. 서로다른 정수 5개 오름차순. 
    // 입력 정수와 응답을 보고 가능한 정수 조합을 확인.
    
    dfs(1, n, q, ans);
    return answer;
}