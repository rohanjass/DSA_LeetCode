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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long res=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            long long minInd=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                auto [node,ind]=q.front();
                q.pop();
                ind-=minInd;
                if(i==0) first=ind;
                if(i==size-1) last=ind;

                if(node->left) q.push({node->left,2*ind+1});
                if(node->right) q.push({node->right,2*ind+2});
            }
        res=max(res,last-first+1);
        }
    return res;
    }
};