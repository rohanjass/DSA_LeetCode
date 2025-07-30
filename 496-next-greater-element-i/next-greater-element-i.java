class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer>mp=new HashMap<>();
        Stack<Integer> st=new Stack<>();
        for(int n:nums2){
            while(!st.isEmpty() && st.peek()<n){
                mp.put(st.pop(),n);
            }
            st.push(n);
        }

        while(!st.isEmpty()){
            mp.put(st.pop(),-1);
        }

        int res[]=new int[nums1.length];
        for(int i=0;i<res.length;i++){
            res[i]=mp.get(nums1[i]);
        }
    return res;
    }
}