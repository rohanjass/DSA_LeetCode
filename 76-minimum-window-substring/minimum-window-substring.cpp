class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        vector<int> mp(128,0);

        for(char c:t){
            mp[c]++;
        }

        int l=0,resLen=INT_MAX,resInd=-1,count=0;

        for(int r=0;r<n;r++){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;

            while(count==t.size()){
                
                if((r-l+1)<resLen){
                    resLen=r-l+1;
                    resInd=l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
        }
    return (resInd==-1)? "": s.substr(resInd,resLen);
    }
};