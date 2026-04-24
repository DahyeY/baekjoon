#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int box = 0;
    vector<int> visit(order.size()+1, 0);
    
    for (int target : order){
        if(box < target) {
            box = target;
            visit[box]++;
            answer++;
        }
        else {
            while(visit[box]){
                box--;
            }
            if(target == box){
                visit[box]++;
                answer++;
            } else {
                return answer;
            }
        }
    }
    
    
    return answer;
}