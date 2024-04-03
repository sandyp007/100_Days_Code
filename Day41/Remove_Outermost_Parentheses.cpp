//  https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s)
    {
        stack<char>sc;
        string ans;
        for(char i:s)
        {
            if(i == '(')
            {
                if(sc.size() > 0)
                {
                    ans += i;
                }
                sc.push(i);
            }
            else
            {
                if(sc.size() > 1)
                {
                    ans += i;
                }
                sc.pop();
            }
        }
        return ans;
    }
};