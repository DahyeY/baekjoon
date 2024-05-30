import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int size = nums.length;

        // key만 사용, value는 더미
        HashSet<Integer> hs = new HashSet<Integer>();
        for (int num : nums) {
            hs.add(num);
        }

        if(hs.size()>size/2) answer = size/2;
        else answer = hs.size();

        return answer;
    }
}