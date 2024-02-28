// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end = nums.size()-1;       // solving using binary search
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target)
                return mid;
            else if (nums[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        }
        return end+1;
    }
};