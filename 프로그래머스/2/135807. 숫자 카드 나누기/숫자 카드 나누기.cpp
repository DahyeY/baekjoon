#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // 1 배열의 가장 작은 수부터 1 까지 -- 하면서 나눌 수 있는지 찾기. 나눌 수 없으면 break
    // 2 배열 돌면서 나눌 수 있으면 break 하기 
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int a = 0;
    int b = 0;
    
    for(int i = arrayA[0]; i>=1; i--){
        bool check = true;
        for(int j=0; j<arrayA.size(); j++){
            if(arrayA[j]%i != 0) {
                check = false;
                break;
            }
        }
        if(check) {
            for(int j=0; j<arrayB.size(); j++){
                if(arrayB[j]%i == 0) {
                    check = false;
                    break;
                }
            }
        }
        if (check){
            a = i;
            break;
        }
    }
    
    for(int i = arrayB[0]; i>=1; i--){
        bool check = true;
        for(int j=0; j<arrayB.size(); j++){
            if(arrayB[j]%i != 0) {
                check = false;
                break;
            }
        }
        if(check) {
            for(int j=0; j<arrayA.size(); j++){
                if(arrayA[j]%i == 0) {
                    check = false;
                    break;
                }
            }
        }
        if (check){
            b = i;
            break;
        }
    }
    
    answer = max(a, b);
    return answer;
}