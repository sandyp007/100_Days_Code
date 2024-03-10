//  https://leetcode.com/problems/reverse-only-letters/

// 1. using stack
class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char>letters;
        for (char c: s)
            if (isalpha(c))  letters.push(c);

        string ans;
        for (char c: s) {
            if (isalpha(c)){
                ans+=(letters.top());
                letters.pop();
            }else
                ans+=c;
        }
        return ans;
    }
};


// 2. Using two pointer

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left=0,right=s.length()-1;
        while(left<right){
            if(isalpha(s[left]) && isalpha(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }else if(!isalpha(s[left]) && !isalpha(s[right])){
                left++;
                right--;
            }else if(!isalpha(s[left])){
                left++;
            }else 
                right--;
        }
        return s;
    }
};