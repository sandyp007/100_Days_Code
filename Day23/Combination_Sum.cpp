//  https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& temp, int target, int i,vector<int>& arr) {
        if (i == arr.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (arr[i] <= target) {
            temp.push_back(arr[i]);
            helper(ans, temp, target - arr[i], i, arr);
            temp.pop_back();
        }
        helper(ans, temp, target, i + 1, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, target, 0, candidates);
        return ans;
    }
};