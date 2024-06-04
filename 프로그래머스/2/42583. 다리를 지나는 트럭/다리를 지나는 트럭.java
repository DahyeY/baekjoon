import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        int weight_sum = 0;
        int time = 0;
        
        for(int truck : truck_weights){
            
            while(true){
                if(weight_sum + truck <= weight && q.size() < bridge_length){
                    q.add(truck);
                    weight_sum += truck;
                    time++;
                    break;
                } else if(q.size() == bridge_length) {
                    weight_sum -= q.remove();
                    if(weight_sum + truck <= weight){
                        q.add(truck);
                        weight_sum += truck;
                        time++;
                        break;
                    } else {
                        q.add(0);
                        time++;
                    }
                } else {
                    q.add(0);
                    time++;
                }
            }
        }
        answer = time + bridge_length;
        return answer;
    }
}