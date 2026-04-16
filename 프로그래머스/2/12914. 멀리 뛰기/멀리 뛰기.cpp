#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n) {
    const int MOD = 1234567;
    
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    long long prev2 = 1; // f(1)
    long long prev1 = 2; // f(2)
    long long current;
    
    for(int i = 3; i <= n; i++) {
        current = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}