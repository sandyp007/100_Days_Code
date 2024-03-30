//  https://leetcode.com/problems/find-peak-element/

class Solution{
public:
    int findPeakElement(vector<int> &nums){
        int n = nums.size();
        if(n == 1){
          return 0;
        }
        int start = 0;
        int end = n - 1;
        while(start < end){
            int mid = start + ((end - start)/2);
            if(nums[mid] > nums[mid + 1]){
                end = mid;
            }
            else{
                start = mid  + 1;
            }
        }
        return start;
    }
};