//  https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char c: text){
            mp[c]++;
        }
        int ans = 0;
        string te = "balloon";
        while(mp['b'] > 0){
            for(char c: te){
                if(mp[c] <= 0){
                    return ans;
                }
                mp[c]--;
            }
            ans++;
        }
        return ans;
    }
};