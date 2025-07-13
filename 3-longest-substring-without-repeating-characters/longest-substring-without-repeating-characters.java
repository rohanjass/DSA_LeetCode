class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int r=0;
        int l=0;
        int maxLen=0;
        Set<Character> st = new HashSet<>();
        while(r<n){
            if(st.contains(s.charAt(r))){
                while(l<r && st.contains(s.charAt(r))){
                    st.remove(s.charAt(l));
                    l++;
                }
            }else{
                st.add(s.charAt(r));
                maxLen=Math.max(maxLen,st.size());
                r++;
            }
        }
    return maxLen;
    }
}