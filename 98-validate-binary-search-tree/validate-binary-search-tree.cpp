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
    bool dfs(TreeNode* node,long upper ,long lower){
        if(node==nullptr) return true;
        if(!(lower<node->val && node->val<upper)) return false;
        return dfs(node->left,node->val,lower) && dfs(node->right,upper,node->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MAX,LONG_MIN);
    }
};