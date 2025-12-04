class Solution {
public:
    string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void def(int ind,string& digits,string path,vector<string>& res){
        if(ind==digits.size()){
            res.push_back(path);
        return;
        }
        int digit=digits[ind]-'0';
        string letters=mp[digit];
        for(int i=0;i<letters.size();i++){
            path.push_back(letters[i]);
            def(ind+1,digits,path,res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path="";
        def(0,digits,path,res);
        return res;
    }
};