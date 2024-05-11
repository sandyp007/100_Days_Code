//  https://leetcode.com/problems/find-center-of-star-graph/description/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n= edges.size();  // n==3

        //vertices are 1 more than edges, so v= n+1;

        //1 based indexing
        vector<int>adj[n+2];  //5: 0, 1, 2, 3, 4
//convert edges to adj list
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        //now any list has n element, means it is at the centre
        /*
        1:2
        2:1,3, 4 (ANSWER)
        3: 2
        4:2

        */
        for(int i=1; i<=n+1; i++)  // x: 1 to 4: 1, 2, 3, 4
        {
            if(adj[i].size()==n)  
            return i;

        }
        return 0;
        
    }
};