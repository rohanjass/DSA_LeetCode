class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> mp1=new HashMap<>();
        Map<Character,Boolean> mp2=new HashMap<>();
        int n=s.length();
        for(int i=0;i<n;i++){
            char c1=s.charAt(i);
            char c2=t.charAt(i);
            if(mp1.containsKey(c1) && mp1.get(c1)!=c2){
                return false;
            }
            if(!mp1.containsKey(c1) && mp2.getOrDefault(c2,false)){
                return false;
            }
            mp1.put(c1,c2);
            mp2.put(c2,true);
        }
    return true;
    }
}