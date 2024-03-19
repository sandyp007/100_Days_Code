//  https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        // We make a dp array of size two greater than the orignal array.
        vector<int> dp(n + 2);
        
        // Cost required to reach 1 or 2 steps forward from end of array is 0.
        dp[n] = dp[n+1] = 0;
        
        // We decide if we have to take one step or two step forward from ith index by deciding which choice cost us less.
        for(int i = n-1;i>=0;i--)
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        
        // We return min of cost required if we start from 0th index of 1th index
        return min(dp[0],dp[1]);
    }
};