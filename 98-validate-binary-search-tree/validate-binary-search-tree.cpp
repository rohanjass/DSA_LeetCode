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
    bool def(TreeNode* root,long lower,long upper){
        if(root==nullptr) return true;
        if(!(lower<root->val && root->val<upper)) return false;
        return def(root->left,lower,root->val) && def(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        return def(root,LONG_MIN,LONG_MAX);
    }
};