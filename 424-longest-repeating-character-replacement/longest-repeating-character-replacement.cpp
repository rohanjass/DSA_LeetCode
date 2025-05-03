class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        vector<int> count(26,0);
        int l=0;
        int maxCount=0;
        int maxWindow=0;

        for(int r=0;r<s.size();r++){
            count[s[r]-'A']++;
            maxCount=max(maxCount,count[s[r]-'A']);

            if(r-l+1-maxCount>k){
                count[s[l]-'A']--;
                l++;
            }

        maxWindow=max(maxWindow,r-l+1);
        }
    return maxWindow;
    }
};