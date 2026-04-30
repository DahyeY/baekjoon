#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canChange(string& a, string& b){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) cnt++;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    vector<int> visited(words.size(), 0);
    
    q.push({begin, 0});
    
    while(!q.empty()){
        auto [from, num] = q.front(); q.pop();
        
        
        
        if(from==target) return num;
        
        for(int i=0; i<words.size(); i++){
            if(visited[i]) continue;
            
            if(canChange(from, words[i])){
                q.push({words[i], num+1});
                visited[i]=1;
            }
        }
    }
    
    
    return 0;
}