//  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    void inorderTraversal(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
           return; 
        inorderTraversal(root->left,res);
        res.push_back(root->val);
        inorderTraversal(root->right,res);
    }
    
    bool findTarget(TreeNode* root, int k) {
         
        vector<int> res; 
        inorderTraversal(root, res);
        
        int low = 0;
        int high = res.size() - 1;
        while(low < high)
        {
            if(res[low] + res[high] == k)
                return true;
            else if(res[low] + res[high] < k)
                low++; 
            else 
                high--;
        }
        return false;
    }
};