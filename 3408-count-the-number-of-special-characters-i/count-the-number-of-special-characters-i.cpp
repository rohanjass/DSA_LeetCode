class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        string s=word;
        for(int i=0;i<n;i++){
            
            if(isupper(s[i])){
                upper[s[i]-'A']=1;
            } 
            if(islower(s[i])){
                lower[s[i]-'a']=1;
            } 
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lower[i] && upper[i]) cnt++;
        }
    return cnt;
    }
};