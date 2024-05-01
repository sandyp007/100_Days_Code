//  https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans ; 
        vector<int> output ;  

        // edge case 
        if (root == NULL)
        {
            return ans ; 
        }

        // insert the first element and separator in the vector 
        queue<TreeNode*> q; 
        q.push(root) ;  //insert the first node the root node 
        q.push(NULL) ;  // the first separator comes after root node 

        while (!q.empty())
        {
            TreeNode *temp = q.front() ; 
            q.pop() ; 
            // if element at the front is a separator means one level has been traversed so we push the 1-D vector storing elements of that level into the 2-D vector that we have to return 
            if (temp == NULL)
            {
                ans.push_back(output) ; 
                output.clear() ; 

                // also if the queue is not empty meaning there are still child nodes present in it we would enter another separator in the queue 
                if (!q.empty())
                {
                    q.push(NULL) ; 
                }
            }
            // else if temp is not NULL
            else
            {
                // insert elements into the 1-D vector 
                output.push_back(temp -> val) ;
                // also check if the left and right nodes of temp are not NULL then insert them into queue as well
                if (temp -> left != NULL)
                {
                    q.push(temp -> left) ;
                }

                if (temp -> right != NULL)
                {
                    q.push(temp -> right) ; 
                }
            }
        }
        return ans ; 
    }
};