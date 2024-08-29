import java.util.HashMap;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        HashMap<String,String> parent = new HashMap<>();
        for(int i = 0; i<enroll.length; i++){
            parent.put(enroll[i], referral[i]);
        }

        HashMap<String, Integer> benefit = new HashMap<>();

        for(int i =0; i<seller.length; i++){
            int money = amount[i]*100;
            String member = seller[i];
            while(money!=0&&!member.equals("-")){
                benefit.put(member, benefit.getOrDefault(member, 0)+money - (money/10));
                member=parent.get(member);
                money/=10;
            }
        }

        int[] answer = new int[enroll.length];
        for(int i =0;i <enroll.length; i++){
            answer[i]=benefit.getOrDefault(enroll[i],0);
            }

        return answer;
    }
}