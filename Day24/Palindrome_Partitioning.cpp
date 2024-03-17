// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    bool palind(string s)
    {
        string a=s;
        reverse(a.begin(),a.end());
        if (a==s) return true;
        else return false;
    }
    
    void call(int ind,vector<vector<string>>& ans,vector<string>& vec,string s)
    {
        if (ind==s.size())
        {
            ans.push_back(vec);
        }
        
        for (int i=ind;i<s.size();i++)
        {
            if (palind(s.substr(ind,i-ind+1)))
            {
                vec.push_back(s.substr(ind,i-ind+1));
                call(i+1,ans,vec,s);
                vec.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        call(0,ans,vec,s);
        return ans;
    }
};