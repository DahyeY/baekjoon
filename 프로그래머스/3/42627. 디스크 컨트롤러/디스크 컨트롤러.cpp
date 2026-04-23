#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int num, req, time;
};

struct cmp {
    bool operator() (Job a, Job b) {
        if(a.time != b.time) return a.time > b.time;
        if(a.req != b.req) return a.req > b.req;
        return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    // 작업시간 짧, 요청시각 빨, 작업 번호 작.
    // 작업번호, 요청시각, 소요시간
    priority_queue<Job, vector<Job>, cmp> q;
    
    int cur_time = 0;
    int fin_time = 0;
    sort(jobs.begin(), jobs.end());
    
    while(idx<jobs.size() || !q.empty()){
        
        while(idx<jobs.size() && jobs[idx][0]<=cur_time){
            q.push({idx,jobs[idx][0],jobs[idx][1]});
            idx++;
        }
        if (!q.empty()) {
            Job cur = q.top(); q.pop();
            cur_time = max(cur_time, cur.req);
            cur_time += cur.time;
            answer += cur_time - cur.req;
        } else {
            cur_time = jobs[idx][0];
        }  
    }
    return answer/jobs.size();
}