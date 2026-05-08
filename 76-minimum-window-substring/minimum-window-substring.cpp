class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128,0);
        int n=s.size();
        for(char i:t){
            mp[i]++;
        }

        int l=0,minWin=INT_MAX,minInd=-1,count=0;

        for(int r=0;r<n;r++){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;

            while(count==t.size()){
                if((r-l+1)<minWin){
                    minWin=r-l+1;
                    minInd=l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
        }
    return (minInd==-1)? "":s.substr(minInd,minWin);
    }
};