// https://leetcode.com/problems/largest-number/

class Solution {
public:
    static bool compare(string a,string b)  // compares strings lexicographically. 
    {   
        string t1=a+b;
        string t2=b+a;

        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
             
        vector<string> str;

        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];

            str.push_back(to_string(ele)); 
        }

      


         sort(str.begin(),str.end(),compare); 
           if(str[0]=="0")
        {
            return "0";
        } 

         string ans="";

         for(int i=0;i<str.size();i++)
         {
             ans+=str[i];
         } 

        return ans;
    }
};