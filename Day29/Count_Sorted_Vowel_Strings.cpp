//  https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    
    //dry run for n=1,2,3,4 and you will see a pattern
    int countVowelStrings(int n) {
        vector<int> ans(5,1);
        for(int i=2;i<=n;i++){
            for(int i=3;i>=0;i--){
                ans[i]+=ans[i+1];
            }
        }
        int res=0;
        for(int i=0;i<5;i++){
            res+=ans[i];
        }
        return res;
    }
};