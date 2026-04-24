#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum = 0;
    long long target = 0;
    vector<int> q;
    
    for(auto n : queue1){
        sum += n;
        q.push_back(n);
    }
    for(auto n : queue2){
        sum += n;
        q.push_back(n);
    }
    
    if(sum%2) return -1;
    else target = sum/2;
    
    // 투포인터
    int l=0, r=queue1.size();
    
    sum = 0;
        
    for(int i =l; i<r; i++){
        sum += q[i];
    }
    
    while(1){
        
        if(sum == target) {
            return answer;
        }
        else if (sum > target) {
            sum -= q[l];
            l++;
            answer++;
        }
        else if (sum < target) {
            sum += q[r];
            r++;
            answer++;
        }
        
        if(answer > 3*queue1.size() || r>q.size()-1) return -1;
        
    }
    
    return answer;
}