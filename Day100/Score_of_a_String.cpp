//  https://leetcode.com/problems/score-of-a-string/

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 0; i+1 <= s.size()-1;i++){
            int a = s[i];
            int b = s[i+1];
            if (a > b){
                sum += a-b;
            }
            else{
                sum += b -a;
            }
        }
        return sum;
    }
};