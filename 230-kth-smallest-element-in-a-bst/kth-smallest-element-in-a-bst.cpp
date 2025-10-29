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
    void def(TreeNode* root,vector<int>& arr){
        if(root==nullptr) return;
        def(root->left,arr);
        arr[0]--;
        if(arr[0]==0) arr[1]=root->val;
        def(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr(2);
        arr[0]=k;
        def(root,arr);
    return arr[1];
    }
};