//  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans{-1, -1};
    //we have to do two binray search operations 
        //one for 1st index.
        int low = 0;
        int high = nums.size()-1;
        while( low <= high){
            int mid = (low+ high) /2;
            if(nums[mid] == target){
                ans[0] = mid;
                //continue searching in left side of the nums to find 1st index of the given target
                high = mid-1;
            }else if (nums[mid] < target){
                //search in right side of the  nums
                 low = mid+1;
            }else{
                //search in left side of the  nums
                high = mid-1;
            }
        }
        //second binary search 
        //to find the last index of the given target
        low = 0;
        high = nums.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target){
                ans[1] = mid;
                //continue searching in right side as we want the last index
                low = mid+1;
            }else if(nums[mid] < target){
                low =  mid+1;
            }else high = mid-1;
        }
        return ans;
        
    }
};