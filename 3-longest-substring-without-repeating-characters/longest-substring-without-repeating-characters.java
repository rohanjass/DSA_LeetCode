class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer>mp= new HashMap<>();

        int left=0,maxLen=0;
        for(int r=0;r<s.length();r++){
            char curr=s.charAt(r);

            if(mp.containsKey(curr)&& left<=mp.get(curr)){
                left=mp.get(curr)+1;
            }
            mp.put(curr,r);
            maxLen=Math.max(maxLen,r-left+1);
        }
    return maxLen;
    }
}