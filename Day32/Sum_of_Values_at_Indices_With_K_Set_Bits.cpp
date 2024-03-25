//  https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0;i<nums.size();i++){
        int c = 0;
        int copy = i;
        while(copy){
            c+= copy & 1;
            copy >>= 1;
        }    
        if(c == k){
            res += nums[i];
        }
        }
        return res;
    }
};

//please upvote if the solution helped you. :) 