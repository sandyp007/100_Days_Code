// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(!isalnum(s[l])) // check if the input value is either an alphabet or a number.
                l++;
            else if(!isalnum(s[r]))
                r--;
            else if(tolower(s[l])!=tolower(s[r])) // check if left pointer is not equal to rifht
                return false;
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};