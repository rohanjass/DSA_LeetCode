class Solution {
public:
    string mapping[10]={"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int ind,string digits,string path,vector<string>& res){
        if(ind==digits.size()){
            res.push_back(path);
        return;
        }
        int digit=digits[ind]-'0';
        string letter=mapping[digit];
        for(int i=0;i<letter.size();i++){
            path.push_back(letter[i]);
            dfs(ind+1,digits,path,res);
            path.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path="";
        if(digits.size()==0) return res;
        dfs(0,digits,path,res);
        return res;
    }
};