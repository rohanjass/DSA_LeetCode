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
    unordered_map<int,int> mp;
    int preInd=0;
    TreeNode* dfs(vector<int>& preorder,int l,int r){
        if(l>r) return nullptr;
        int nodeVal=preorder[preInd];
        preInd++;
        TreeNode* root= new TreeNode(nodeVal);
        int indInInorder=mp[nodeVal];
        root->left=dfs(preorder,l,indInInorder-1);
        root->right=dfs(preorder,indInInorder+1,r);
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return dfs(preorder,0,preorder.size()-1);
    }
};