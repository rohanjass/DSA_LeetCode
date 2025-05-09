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
    bool dfs(TreeNode* node,long lower,long higher){
        if(node==nullptr) return true;
        if(!(lower<node->val && node->val<higher)) return false;
        return dfs(node->left,lower,node->val) && dfs(node->right,node->val,higher);
    }
    bool isValidBST(TreeNode* root) {
        long lower=LONG_MIN;
        long higher=LONG_MAX;
        return dfs(root,lower,higher);
    }
};