class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26,0);
        int i=0,maxFreq=0,res=0;
        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);

            while((j-i+1)-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
            }
        
        res=max(res,j-i+1);
        }
        return res;
    }
};