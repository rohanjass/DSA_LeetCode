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
    int preInd=0;
    unordered_map<int,int>mp;
    TreeNode* dfs(vector<int>& preorder,int l,int r){
        if(l>r) return nullptr;
        int nodeVal=preorder[preInd];
        preInd++;
        TreeNode* root=new TreeNode(nodeVal);
        int mid=mp[nodeVal];
        root->left=dfs(preorder,l,mid-1);
        root->right=dfs(preorder,mid+1,r);
    return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return dfs(preorder,0,inorder.size()-1);
    }
};