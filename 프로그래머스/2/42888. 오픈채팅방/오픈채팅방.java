import java.util.HashMap;
import java.util.ArrayList;


class Solution {
    public String[] solution(String[] record) {
        ArrayList<String> list = new ArrayList<>();
        HashMap<String, String> nickname = new HashMap<>(); 
        
        for(int i = 0; i<record.length; i++){
            String[] cmd = record[i].split(" ");
            switch(cmd[0]) {
                case "Enter" :
                case "Change":
                    nickname.put(cmd[1], cmd[2]);
                    break;                    
            }
        }
        for(int i = 0; i<record.length; i++){
            String[] cmd = record[i].split(" ");
            switch(cmd[0]) {
                case "Enter" :
                    list.add( nickname.get(cmd[1])+"님이 들어왔습니다.");
                    break;
                case "Leave":
                    list.add( nickname.get(cmd[1])+"님이 나갔습니다.");
                    break;                    
            }
        }
        
        String[] answer = new String[list.size()];
        
        for(int i = 0; i<list.size(); i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}