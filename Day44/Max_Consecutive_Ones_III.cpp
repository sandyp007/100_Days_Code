//  https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0;
        int cnt = 0; 
        int ans = 0; 
        for(int i = 0 ;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
            }
            // when cnt becomes more than k we reduce our window 
            while( cnt > k)
            {
                if(nums[j] == 0)
                {
                    cnt--;
                }
                j++;
            }
            ans = max(ans,i - j + 1);
        }
        return ans; 
    }
};