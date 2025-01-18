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
    int Tran(TreeNode* node,int& cnt,int pathMax){
        if(node==0) return 0;
        

        if(node->val>=pathMax) {
            pathMax=max(pathMax,node->val);
            cnt++;
        }
        Tran(node->left,cnt,pathMax);
        Tran(node->right,cnt,pathMax);
    return cnt;
    }
    int goodNodes(TreeNode* root) {
        int cnt=0,pathMax=INT_MIN;
        Tran(root,cnt,pathMax);
        return cnt;
    }
};