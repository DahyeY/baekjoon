function solution(s) {
    var answer = 0;
    var str;
    if(s[0]==='+') {
        str = s.slice(1, s.length);
        answer = parseInt(str);
    }
    else if(s[0]==='-') {
        str = s.slice(1, s.length);
        answer = -1 * parseInt(str);
    }
    else answer = parseInt(s);
    return answer;
}