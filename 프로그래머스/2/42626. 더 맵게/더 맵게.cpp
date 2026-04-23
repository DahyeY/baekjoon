#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 가장 낮은 2개의 음식. 
    // 가장 안맵 + 두번째 안맵*2
    priority_queue<long long, vector<long long>, greater<long long>> q;
    
    for(int s : scoville){
        q.push(s);
    }
    
    while(q.top()<K && q.size()>1){
        answer++;
        long long a = q.top();
        q.pop();
        long long b= q.top();
        q.pop();
        q.push(a+b*2);
    }
    if(q.size()==1 && q.top()<K) return -1;
    
    return answer;
}