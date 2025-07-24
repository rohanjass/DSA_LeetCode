class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(128,0);
        int cnt=0,r=0,l=0,startInd=-1;
        int minLen=INT_MAX;
        int n=s.size();
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    startInd=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
        r++;
        }
    return (startInd==-1)? "" : s.substr(startInd,minLen);
    }
};