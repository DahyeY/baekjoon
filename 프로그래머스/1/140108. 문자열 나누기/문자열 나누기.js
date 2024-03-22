function solution(s) {
    var answer = 0;
    var count = 0;
    
        var x = s[0];
        var a=0, b=0;
        for(var i = 0; i<s.length - 1; i++){
            if(s[i] === x) a++;
            else b++;
            
            if(a===b) {
                count++;
                a = 0;
                b = 0;
                x = s[i+1];
            }
        }
    
    answer = count+1;
    return answer;
}