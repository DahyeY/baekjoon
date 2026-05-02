#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // N 명씩 팀 
    // 각 1명씩 숫자 공개. 비기면 승점 x
    
    // A 배열에 따라 B가 최대 승점 얻도록. 
    
    // a, b 정렬 후 b 원소 큰 순서대로 정렬
    // b 큰 원소부터 a 훑기. a가 b보다 작으면 1더하고 다음 수로. 
    // a 도 다음 수부터. 
    int idx = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int b : B) {
        
        for(int i=idx; i<A.size(); i++){
            int a=A[i];
            
            if(b>a) {
                answer++;
                idx = i+1;
                break;
            } 
        }
        
    }
    
    return answer;
}