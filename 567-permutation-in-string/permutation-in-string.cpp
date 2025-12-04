class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> countS1(26,0),countWindow(26,0);
        for(char c:s1) countS1[c-'a']++;
        for(int i=0;i<s2.size();i++){
            countWindow[s2[i]-'a']++;
            
            if(i>=s1.size()){
                countWindow[s2[i-s1.size()]-'a']--;
            }

            if(countS1==countWindow) return true;
        }
    return false;
    }
};