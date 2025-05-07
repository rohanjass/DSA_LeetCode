class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(const auto& s:strs){
            string sortedS=s;
            sort(sortedS.begin(),sortedS.end());
            mp[sortedS].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& p:mp){
            res.push_back(p.second);
        }
    return res;
    }
};