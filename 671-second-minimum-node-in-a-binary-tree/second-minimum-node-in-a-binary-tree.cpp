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
    long dfs(TreeNode* node,int rootVal){
        if(!node) return LONG_MAX;
        if(node->val>rootVal) return node->val;
        long left=dfs(node->left,rootVal);
        long right=dfs(node->right,rootVal);
        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int sMini=dfs(root,root->val);
        return (sMini==LONG_MAX)? -1:sMini;
    }
};