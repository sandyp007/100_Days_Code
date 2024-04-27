//  https://leetcode.com/problems/sort-the-people/


class Solution 
{
public:
    
    static bool comp(pair<int, string> &a, pair<int, string> &b) //this function sort in decreasing order
    {
        return a.first >= b.first;
    }
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int, string>> p;
        
        for(int i=0; i<names.size(); i++)
            p.push_back({heights[i], names[i]});

        
        sort(p.begin(), p.end(), comp);
        
        vector<string> res;
        for(auto it:p)
            res.push_back(it.second);
        
        return res;
    }
};