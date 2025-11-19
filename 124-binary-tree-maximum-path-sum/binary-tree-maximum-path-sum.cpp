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
    int def(TreeNode* root,int& maxi){
        if(root==nullptr) return 0;

        int rightSum=max(0,def(root->right,maxi));
        int leftSum=max(0,def(root->left,maxi));

        maxi=max(maxi,rightSum+root->val+leftSum);
        return max(leftSum,rightSum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        def(root,maxi);
        return maxi;
    }
};