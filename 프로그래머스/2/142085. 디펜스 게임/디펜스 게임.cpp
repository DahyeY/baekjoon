#include <string>
#include <vector>
#include <queue>

using namespace std;
int MAX = 0;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;

    for(int i : enemy){
        pq.push(i);
        n= n-i; 
        answer++;
        if(n<0&&k>0){
            n=n+pq.top();
            pq.pop();
            k--;
        }
        if(n<0&&k==0){
            answer--;
            break;
        }
    }
    
    return answer;
}