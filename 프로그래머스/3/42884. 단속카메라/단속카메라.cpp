#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    // 나간 지점 기준으로 정렬.
    // 카메라 설치 후 걸리는 애들 넘어감.
    // 카메라 벗어나면 다음 요소 종점으로 카메라 위치 변경
    
    sort(routes.begin(), routes.end(), cmp);
    int camera = -30001;    
    for(auto route : routes){
        if(route[0] > camera) {
            camera = route[1];
            answer++;
        }
        
    }
    
    
    return answer;
}