//  https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/

class Solution{
public:
    int countPairs(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int count=0;
        while(start<end)
        {
            if( nums[start]+nums[end]<target )
            {
                count=count+end-start;
                start++;
            }
            else
                end--;
        }   
        return count;
    }

};