// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop();        break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop();        break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop();        break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};