//  https://leetcode.com/problems/deepest-leaves-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
			
			//since bfs is a level by level order traversal and we want the sum of last level
			//we remove the sum achieved by previous levels
			
            sum = 0;
            
            for(int i=0; i<sz; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                
				//calculate the current level's sum
				
                sum += front->val;
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
		//this will eventually have the sum of the last level which will be our answer
		
        return sum;
    }
};

