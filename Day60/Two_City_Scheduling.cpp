//  https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(),costs.end(),[](vector<int>a,vector<int>b){
           return a[0]-b[0]<a[1]-b[1];
        });
        
        int res=0;
        int n=costs.size();
        for(int i=0;i<n/2;i++)
        {
            res+=(costs[i][0])+(costs[n-i-1][1]);
        }
        return res;
    }
};