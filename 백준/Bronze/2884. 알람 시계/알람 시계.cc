#include <iostream>
using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;

    if (M < 45)
    {
        H -= 1;
        M = M + 60 - 45;
    }
    else
    {
        M = M - 45;
    }

    if (H < 0)
    {
        H += 24;
    }

    cout << H << " " << M;
}