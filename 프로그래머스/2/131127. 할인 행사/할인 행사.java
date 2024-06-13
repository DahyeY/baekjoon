import java.util.HashMap;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        HashMap<String,Integer> wantToBuy = new HashMap<>();
        
        for(int i =0;i<want.length; i++){
            wantToBuy.put(want[i], number[i]);
        }
                
        for(int i = 0; i<discount.length-10+1;i++){
            HashMap<String,Integer> canBuy = new HashMap<>();
            for(int j=0; j<10; j++){
                canBuy.put(discount[i+j], canBuy.getOrDefault(discount[i+j], 0)+1);
            }
            if(wantToBuy.equals(canBuy)) 
                answer++;
            canBuy.clear();
        }
        
        return answer;
    }
}