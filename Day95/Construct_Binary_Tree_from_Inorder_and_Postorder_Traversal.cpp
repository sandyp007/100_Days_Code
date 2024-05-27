//  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

class Solution {
public:
 unordered_map<int,int>m;
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int &postIndex){
        if(start>end) return NULL;
         int inorderIndex = m[postorder[postIndex]];

        TreeNode* root = new TreeNode(inorder[inorderIndex]);    
        
        (postIndex)--;
      root->right=solve(inorder,postorder,inorderIndex+1,end,postIndex);
        root->left=solve(inorder,postorder,start,inorderIndex-1,postIndex);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++){
           m[inorder[i]] = i;
            
        }
        int postIndex=postorder.size()-1;
        return solve(inorder,postorder,0,postorder.size()-1,postIndex);
    }
};