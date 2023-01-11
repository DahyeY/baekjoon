#include <iostream>
using namespace std;

int main()
{
    //어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
    //어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
    //예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다.
    //반대로, 생성자가 여러 개인 자연수도 있을 수 있다.
    //자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.
    //자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
    int N, num, min = 0;
    int n1, n2, n3, n4, n5, n6, n7;

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        num = N - i;
        n7 = num / 1000000;
        n6 = (num - n7 * 1000000) / 100000;
        n5 = (num - n7 * 1000000 - n6 * 100000) / 10000;
        n4 = (num - n7 * 1000000 - n6 * 100000 - n5 * 10000) / 1000;
        n3 = (num - n7 * 1000000 - n6 * 100000 - n5 * 10000 - n4 * 1000) / 100;
        n2 = (num - n7 * 1000000 - n6 * 100000 - n5 * 10000 - n4 * 1000 - n3 * 100) / 10;
        n1 = (num - n7 * 1000000 - n6 * 100000 - n5 * 10000 - n4 * 1000 - n3 * 100 - n2 * 10);
        if ((num + n7 + n6 + n5 + n4 + n3 + n2 + n1) == N)
            min = num;
    }

    // printf("%d %d %d %d %d %d %d", n7, n6, n5, n4, n3, n2, n1);
    cout << min;
    return 0;
}