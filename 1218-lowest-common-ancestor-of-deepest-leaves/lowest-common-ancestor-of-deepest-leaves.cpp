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
    pair<int,TreeNode*> def(TreeNode* root){
        if(root==nullptr) return {0,nullptr};
        auto l=def(root->left);
        auto r=def(root->right);

        if(l.first>r.first){
            return{l.first+1,l.second};
        } else if(l.first<r.first){
            return {r.first+1,r.second};
        } else {
            return {l.first+1,root};
        }

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return def(root).second;
    }
};