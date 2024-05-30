//  https://leetcode.com/problems/decode-ways/description/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return fn(0, s, dp);
    }

    int fn(int ind, string s, vector<int>& dp){
        int n = s.size();
        if(ind==n) return 1;
        if(ind>n) return 0;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int l=fn(ind+1, s, dp);
        int r=0;
        if(s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')) r=fn(ind+2, s, dp);
        return dp[ind]=l+r;
    }
};