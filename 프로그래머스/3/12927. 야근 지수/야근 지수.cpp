#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int work:works){
        pq.push(work);
    }
    
    for(int i=0;i<n;i++){
        int n = pq.top(); pq.pop();
        if(n==0) return 0;
        pq.push(n-1);
    }
    
    while(!pq.empty()){
        answer += pq.top()*pq.top();
        pq.pop();
    }
    
    return answer;
}