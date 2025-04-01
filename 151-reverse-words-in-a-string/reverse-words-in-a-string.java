import java.util.StringTokenizer;

class Solution {
    public String reverseWords(String s) {
        StringTokenizer st=new StringTokenizer(s," ");
        StringBuilder sb=new StringBuilder();
        while(st.hasMoreTokens()){
            sb.insert(0,st.nextToken() + " ");
        }
        return sb.toString().trim();
    }
}