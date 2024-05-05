//  https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    if (t1 && t2) { // If both nodes exist, add their values then look at the next node. 
        t1->val+=t2->val;
        t1->left = mergeTrees(t1->left,t2->left);  
        t1->right = mergeTrees(t1->right, t2->right);
    } else { // If one node doesn't exist, link it back to the calling node.
	    return t1 ? t1 : t2;  
	}
    
    return t1; // Return the first tree, which is now altered. No need to create a new node, which bloats memory.
}
};