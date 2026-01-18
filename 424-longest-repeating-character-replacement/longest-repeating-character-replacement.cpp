class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>freq (26,0);
        int l=0,maxFreq=0,res=0;
        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq,freq[s[r]-'A']);

            while((r-l+1)-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
    return res;
    }
};