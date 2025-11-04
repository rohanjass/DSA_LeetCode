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
    int def(TreeNode* node){
        if(node==nullptr) return 0;

        int rh=def(node->right);
        int lh=def(node->left);

        if(node->left==nullptr) return 1+rh;
        if(node->right==nullptr) return 1+lh;

        return 1+min(rh,lh);
    }
    int minDepth(TreeNode* root) {
    
        return def(root);

    }
};