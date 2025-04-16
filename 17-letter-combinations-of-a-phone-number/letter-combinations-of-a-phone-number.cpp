class Solution {
public:
    string mapping[10]={"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int i,string digits,string path,vector<string>& res){
        if(i==digits.size()){
            res.push_back(path);
        return;
        }
        int digit=digits[i]-'0';
        string letter=mapping[digit];
        for(int j=0;j<letter.size();j++){
            path.push_back(letter[j]);
            dfs(i+1,digits,path,res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> res;
        if(digits.size()==0) return res;
        dfs(0,digits,path,res);
    return res;
    }
};