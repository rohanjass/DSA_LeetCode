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
    void dfs(TreeNode* root,vector<int>& a){
        if(root==nullptr) return;
        dfs(root->left,a);
        a[0]--;
        if(a[0]==0){
            a[1]=root->val;
        return;
        }
        dfs(root->right,a);
    return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>a(2);
        a[0]=k;
        dfs(root,a);
    return a[1];
    }
};