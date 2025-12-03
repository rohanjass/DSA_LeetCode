class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128,0);
        int cnt=0,l=0,r=0,startInd=-1;
        int minLen=INT_MAX;
        for(char c:t){
            mp[c]++;
        }

        while(r<s.size()){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            while(cnt==t.size()){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    startInd=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
        r++;
        }
    return (startInd==-1)? "":s.substr(startInd,minLen);
    }
};