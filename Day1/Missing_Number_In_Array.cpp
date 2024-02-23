// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int Tsum = (n*(n+1))/2;
        return  Tsum - accumulate(nums.begin(),nums.end(),0);
        
    }
}; 

// This solution works by calculating the sum of all numbers from 1 to N in a regular sequence
//and then subtracting the actual sum of the given array. The result will be the missing.
