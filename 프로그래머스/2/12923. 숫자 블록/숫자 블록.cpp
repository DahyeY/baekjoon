#include <vector>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (long long num = begin; num <= end; num++) {
        if (num == 1) {
            answer.push_back(0);
            continue;
        }

        int result = 1;

        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                long long pair = num / i;

                if (pair <= 10000000) {
                    result = pair;
                    break;
                }

                if (i <= 10000000) {
                    result = i;
                }
            }
        }

        answer.push_back(result);
    }

    return answer;
}