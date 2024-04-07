//  https://leetcode.com/problems/maximum-strong-pair-xor-i/

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto i: nums) cout<<i<<",";
        cout<<endl;
        int i=0,j=1;
        int s=0,mx=0;
        for(;j<nums.size();j++){
            if(abs(nums[j]-nums[i])<=min(nums[i],nums[j])) {
                s= nums[j] ^ nums[i];
                mx=max(s,mx);
                cout<<s<<",";
            }
            else {
                i++;
                j=i;
            }
            if(j==nums.size()-1 && i<j) {
                j=i;
                i++;
            } 
        }
        return mx;
    }
}; 