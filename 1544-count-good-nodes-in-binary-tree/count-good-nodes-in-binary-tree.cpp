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
    void dfs(int &cnt,int pathMax,TreeNode* root){
        if(!root) return;
        if(root->val >=pathMax){
        cnt++;
            pathMax=root->val;
        }
        dfs(cnt,pathMax,root->left);
        dfs(cnt,pathMax,root->right);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0,pathMax=INT_MIN;
        dfs(cnt,pathMax,root);
        return cnt;
    }
};