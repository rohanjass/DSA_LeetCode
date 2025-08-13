class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>mp;
        int maxLen=0;
        int l=0,r=0;
        while(r<s.size()){
            while(mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
            maxLen=max(maxLen,r-l+1);
            r++;
        }
    return maxLen;
    }
};