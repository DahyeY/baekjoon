#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct Task {
    string name;
    int start;   // 시작 시간 (분 단위)
    int remain;  // 남은 시간
};

// 시작 시간 기준 정렬
bool cmp(const Task &a, const Task &b) {
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<Task> tasks;

    // 입력 파싱
    for (auto &p : plans) {
        int h = stoi(p[1].substr(0, 2));
        int m = stoi(p[1].substr(3, 2));
        tasks.push_back({p[0], h * 60 + m, stoi(p[2])});
    }

    // 시작 시간 순으로 정렬
    sort(tasks.begin(), tasks.end(), cmp);

    vector<string> answer;
    stack<Task> st;
    int curTime = tasks[0].start;
    st.push(tasks[0]);

    for (int i = 1; i < tasks.size(); i++) {
        Task next = tasks[i];
        int gap = next.start - curTime;

        // 현재 과제(스택 top) 처리
        while (gap > 0 && !st.empty()) {
            Task cur = st.top(); st.pop();

            if (cur.remain <= gap) {
                // 과제를 다 끝낼 수 있음
                gap -= cur.remain;
                curTime += cur.remain;
                answer.push_back(cur.name);
            } else {
                // 다 못 끝내면 남은 거 다시 push
                cur.remain -= gap;
                curTime += gap;
                gap = 0;
                st.push(cur);
            }
        }

        // 새로운 과제 시작
        curTime = next.start;
        st.push(next);
    }

    // 남은 과제 처리
    while (!st.empty()) {
        answer.push_back(st.top().name);
        st.pop();
    }

    return answer;
}