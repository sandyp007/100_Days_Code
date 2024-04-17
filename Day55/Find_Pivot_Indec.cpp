//  https://leetcode.com/problems/find-pivot-index/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0, rSum = 0, n = nums.size();

        for (int i = 0; i < n; i++)
            rSum = rSum + nums[i];

        for (int i = 0; i < n; i++) {
            rSum = rSum - nums[i];
            if (lSum == rSum)
                return i;
            lSum = lSum + nums[i];
        }
        return -1;
    }
};