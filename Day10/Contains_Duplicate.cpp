// https://leetcode.com/problems/contains-duplicate/

// Approach 1 using counter
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int cnt=1;
       for(int i=0;i<n-1;i++)
        {
          if(nums[i]==nums[i+1])
            {
              cnt++;
            }
        }
         if(cnt>1)
           {
             return true;
           }
        else
          {
            return false;  
          }
    } 
};

// Approach 2 using set, set cointains unique value

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
     {
        return nums.size()!=set(nums.begin(),nums.end()).size();
     }  
};