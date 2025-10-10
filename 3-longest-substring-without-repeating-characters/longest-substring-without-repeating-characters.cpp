class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256,-1);
        int l=0,res=0;
        for(int r=0;r<s.size();r++){
            int c=s[r];
            if(arr[c]>=l){
                l=arr[c]+1;
            }
            arr[c]=r;
            res=max(res,r-l+1);
        }
    return res;
    }
};