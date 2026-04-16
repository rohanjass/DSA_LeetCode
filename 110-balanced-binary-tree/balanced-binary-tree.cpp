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
    int func(TreeNode* root){
        if(root==nullptr) return 0;

        int lh=func(root->left);
        if(lh==-1) return -1;
        
        int rh=func(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;
    return 1+max(rh,lh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
    return (func(root)!=-1);
    }
};