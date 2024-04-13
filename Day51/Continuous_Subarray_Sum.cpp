//  https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int total=0;
        
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            //finding remainder
            int r=total%k;
            //find function -> returns the iterator to that element if given key exists in the map and if not it return to the end of the map iterator
            if(mp.find(r)==mp.end()){
                mp[r]=i;
            }
            //checks if the size of subarray is greater than 1
            else if(i-mp[r]>1)
            return true;
        }
        return false;
    }
};