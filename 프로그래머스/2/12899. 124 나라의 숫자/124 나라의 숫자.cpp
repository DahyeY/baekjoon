#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<char> st;
    
    // 3진법.... 
    int q = 0, r = 0;
    

    
    while(n != 0) {
        q = n/3;
        r = n%3;
        
        switch(r) {
            case 1:
                st.push('1');
                n = q;
                break;
            case 2:
                st.push('2');
                n = q;
                break;
            case 0:
                st.push('4');
                n = q-1;
                break;
            default:
                break;
        }
        
        
    }
    
    while (!st.empty()){
        answer += st.top();
        st.pop();
    }
        
    
    
    return answer;
}