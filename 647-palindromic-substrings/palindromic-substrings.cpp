class Solution {
public:
    int countPal(int l,int r,string s){
        int res=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            res++;
            l--;
            r++;
        }
    return res;
    }
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            res+=countPal(i,i,s);
            res+=countPal(i,i+1,s);
        }
    return res;
    }
};