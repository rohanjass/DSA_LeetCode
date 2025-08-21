/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> res=new ArrayList<>();
        dfsSerial(root,res);
        return String.join(",",res);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] nodes=data.split(",");
        int[] index ={0};
        return dfsDeserial(nodes,index);
    }

    private void dfsSerial(TreeNode node,List<String> res){
        if(node==null){
            res.add("N");
            return;
        }
        res.add(String.valueOf(node.val));
        dfsSerial(node.left,res);
        dfsSerial(node.right,res);
    } 

    private TreeNode dfsDeserial(String[] data,int[] i){
        if(data[i[0]].equals("N")){
            i[0]++;
            return null;
        }
        TreeNode root=new TreeNode(Integer.parseInt(data[i[0]]));
        i[0]++;
        root.left=dfsDeserial(data,i);
        root.right=dfsDeserial(data,i);

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));