//  https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return helper(s,idx);      
    }

    int helper(string s, int& idx) {
        int res = 0;
        int sign = 1; // '+'=1, '-'=-1
        int number = 0;
        
        for(;idx<s.size(); idx++){
            char x=s[idx]; //current char

            if(x==' ') continue;
            else if(x=='+'||x=='-') {
                res+= sign*(number);
                number=0;
                sign = (x=='+')?1:-1;
            }
            else if(x=='(') res += sign*helper(s, ++idx);
            else if(x==')') break;
            else number = number*10+(x-'0');  
        }  
        return res+sign*(number);      
    }
};