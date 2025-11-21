class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> first(26,-1),last(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(first[c]==-1) first[c]=i;
            last[c]=i;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && first[i]!=last[i]){
                unordered_set<char> set;
                for(int j=first[i]+1;j<last[i];j++){
                    set.insert(s[j]);
                }
            res+=set.size();
            }
        }
    return res;
    }
};