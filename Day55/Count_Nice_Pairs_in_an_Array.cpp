// https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int rev(int n)
    {
        int re=0;
        while(n>0)
        {
            re= re*10 + n%10;
            n/=10;
        }
        return re;
    }  
    long long fact(int n)
    {
        if(n==1)
            return 1;
        return n + fact(n-1);
    }
    int countNicePairs(vector<int>& nums) {
        long count=0;
        const int mod = 1000000007;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]= nums[i] - rev(nums[i]);
        }
        map<int,int> mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        for(auto i: mp)
        {
            if(i.second > 1)
                count = (count % mod + fact(i.second-1) ) % mod ;
        }
        return count ;
    }
};