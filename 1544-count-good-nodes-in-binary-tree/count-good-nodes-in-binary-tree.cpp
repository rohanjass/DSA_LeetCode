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
    
    void dfs(TreeNode* node,int pathMax,int& cnt){
        if(node==nullptr) return;
        if(node->val>=pathMax){
            cnt++;
            pathMax=node->val;
        }
        dfs(node->right,pathMax,cnt);
        dfs(node->left,pathMax,cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        dfs(root,INT_MIN,cnt);
    return cnt;
    }
};