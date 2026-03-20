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
    void func(TreeNode* root,int pathMax,int& cnt){
        if(root==nullptr) return;
        if(root->val>=pathMax){
            cnt++;
            pathMax=root->val;
        } 
        func(root->left,pathMax,cnt);
        func(root->right,pathMax,cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        func(root,INT_MIN,cnt);
    return cnt;
    }
};