#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;
// 2명. 토핑 종류의 수 동일하도록.
// 2개의 해시셋 사용. 

int solution(vector<int> topping) {
    int answer = 0;
    
    
    vector<int> left(topping.size()), right(topping.size());
    unordered_set<int> s;
    
    for(int i=0; i<topping.size(); i++){
        s.insert(topping[i]);
        left[i]=s.size();
    }
    s.clear();
    
    for(int i=topping.size()-1; i>=0; i--){
        s.insert(topping[i]);
        right[i]=s.size();
    }
    
    for(int i=0; i<topping.size(); i++){
        if(left[i]==right[i+1]) answer++;
    }
    
    return answer;
}