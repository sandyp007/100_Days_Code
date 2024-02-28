// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    int n = numRows;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        vector<int>t(i+1);
        ans.push_back(t);

        for(int j = 0;j<=i;j++){
            if(i==j || j==0){
                ans[i][j] = 1;
            }
            else{
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
    }
    return ans;
    }
};