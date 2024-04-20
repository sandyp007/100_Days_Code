class Solution {
public:
    int longestPalindrome(string s) {
        // SUGGEST SOME IMPROVEMENTS IN COMMENTS
        int n = s.size(), cnt = 0;
        if(n==1 || n==0) return n;
        if(n==2) {
            if(s[0] == s[1]) return 2;
            return 1;
        } 

        unordered_map<char, int> mp;

        for(auto i:s) {
            ++mp[i];
        }

        bool evenExist = false, oneExist = false, oddExist = false;

        for(auto i:mp) {
            // IF one exist, that means, we have to ignore it for now
            if(i.second == 1) {
                oneExist = true;
            }

            // IF EVEN EXIST, just add it to count;
            else if(i.second%2==0) {
                evenExist = true;
                cnt += i.second;
            }

            // If ODD EXIST, and its greater than 2, just add it to count with - 1;
            else if(i.second > 2 && i.second%2 != 0) {
                cnt += i.second-1;
                oddExist = true;
            }

        }

        // IF EVERY or IF ODD NOT EXIST or If EVEN NOT EXIST or IF NOT ONE EXIST or IF ONLY ODD EXIST
        if(oddExist && evenExist && oneExist || 
            !oddExist && evenExist && oneExist || 
            oddExist && !evenExist && oneExist ||
            oddExist && evenExist && !oneExist ||
            oddExist && !evenExist && !oneExist) {
            return cnt+1;
        }
        
        else return cnt;
    }
};