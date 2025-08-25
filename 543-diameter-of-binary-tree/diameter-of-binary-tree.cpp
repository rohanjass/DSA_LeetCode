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
    int dfs(TreeNode* node,int &dia){
        if(node==nullptr) return 0;

        int leftH=dfs(node->left,dia);
        int rightH=dfs(node->right,dia);
        dia=max(dia,leftH+rightH);
    return max(leftH,rightH)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        dfs(root,dia);
    return dia;
    }
};