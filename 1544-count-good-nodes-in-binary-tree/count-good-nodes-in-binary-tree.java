/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    void dfs(TreeNode node ,int pathMax,int[] cnt){
        if(node==null) return;
        if(node.val>=pathMax){
            cnt[0]++;
            pathMax=node.val;
        } 
        dfs(node.left,pathMax,cnt);
        dfs(node.right,pathMax,cnt);
    }
    public int goodNodes(TreeNode root) {
        int[] cnt=new int[1];
        dfs(root,Integer.MIN_VALUE,cnt);
        return cnt[0];
    }
}