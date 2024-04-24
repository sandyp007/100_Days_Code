//  https://leetcode.com/problems/delete-greatest-value-in-each-row/

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        unordered_map<int, priority_queue<int>> mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                mp[i].push(grid[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<grid[0].size();i++)
        {
            int maxval=-1;
            for(int j=0;j<grid.size();j++)
            {
            
            int temp=mp[j].top();
            mp[j].pop();
            maxval=max(maxval,temp);
            }
            sum+=maxval;
        }
        return sum;
    }
};