//  https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int i=0,j=0,n=s.length(),k=3;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp.size()==k){
                    ans++;
                }
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};