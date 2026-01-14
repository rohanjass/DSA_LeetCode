class Solution {
public:
    void def(int i,string& s,vector<string>& res){
        if(i>=s.size()){
            res.push_back(s);
            return;
        }
        char ch=s[i];
        if(isdigit(ch)){
            def(i+1,s,res);
        } else {
            s[i]=tolower(ch);
            def(i+1,s,res);

            s[i]=toupper(ch);
            def(i+1,s,res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        def(0,s,res);
        return res;
    }
};