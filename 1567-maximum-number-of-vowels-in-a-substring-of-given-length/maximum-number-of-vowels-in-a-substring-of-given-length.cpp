class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
    return false;
    }
    int maxVowels(string s, int k) {
        int l=0,r=k-1;
        int res=0,vCnt=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) vCnt++;
        }
        res=vCnt;
        for(int i=k;i<s.size();i++){
            if(isVowel(s[i])) vCnt++;
            if(isVowel(s[i-k])) vCnt--;
            res=max(res,vCnt);
        }
    return res;
    }
};