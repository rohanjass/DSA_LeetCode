class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int> res;
        int end=0,size=0;
        for(int i=0;i<s.size();i++){
            size++;
            end=max(end,mp[s[i]]);
            if(i==end){
                res.push_back(size);
                size=0;
            }
        }
    return res;
    }
};