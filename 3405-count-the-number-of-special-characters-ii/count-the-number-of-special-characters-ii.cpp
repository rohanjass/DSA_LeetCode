class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> lower(26,-1);
        vector<int> upper(26,-1);    
        int cnt=0;
        string& s=word;
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                lower[s[i]-'a']=i;
            } else{
                if(upper[s[i]-'A']==-1){
                    upper[s[i]-'A']=i;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1 && lower[i]<upper[i]){
                cnt++;
            }
        }
    return cnt;
    }
};