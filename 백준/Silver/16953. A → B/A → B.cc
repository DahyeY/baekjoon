//너비우선탐색
//정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.
// 2를 곱한다.
// 1을 수의 가장 오른쪽에 추가한다.
// A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 1; //연산 횟수 +1을 출력해야하므로 cnt를 1로 초기화

    // b에서 2를 나누거나 1을 제거하면서 a를 찾는 역으로 진행하는 알고리즘
    while (1)
    {
        // a > b 이면 불가능하므로 -1 출력
        if (a > b)
        {
            cout << "-1";
            break;
        }
        // a = b 이면 cnt 출력
        if (a == b)
        {
            cout << cnt;
            break;
        }
        // b의 마지막 자리가 1이면 10으로 나눠 맨 뒤의 1을 제거
        else if (b % 10 == 1)
            b /= 10;
        // b의 마지막 자리가 짝수이면 2로 나누기
        else if (b % 2 == 0)
            b /= 2;
        //위의 경우에 해당하지 않으면 불가능한 경우이므로 -1 출력
        else
        {
            cout << "-1";
            break;
        }
        cnt++;
    }
    return 0;
}