#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    unordered_map<int, int> valid;

    for (string s : operations) {
        char cmd = s[0];
        int num = stoi(s.substr(2));

        if (cmd == 'I') {
            maxH.push(num);
            minH.push(num);
            valid[num]++;
        } 
        else {
            if (num == 1) {
                // 최대값 삭제
                while (!maxH.empty() && valid[maxH.top()] == 0) maxH.pop();

                if (!maxH.empty()) {
                    valid[maxH.top()]--;
                    maxH.pop();
                }
            } 
            else {
                // 최소값 삭제
                while (!minH.empty() && valid[minH.top()] == 0) minH.pop();

                if (!minH.empty()) {
                    valid[minH.top()]--;
                    minH.pop();
                }
            }
        }
    }

    // 마지막 정리 (쓰레기 제거)
    while (!maxH.empty() && valid[maxH.top()] == 0) maxH.pop();
    while (!minH.empty() && valid[minH.top()] == 0) minH.pop();

    if (maxH.empty() || minH.empty()) {
        return {0, 0};
    }

    return {maxH.top(), minH.top()};
}