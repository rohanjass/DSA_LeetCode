class Solution {
public:
    void dfs(int open,int close,vector<string>& res,string& stackStr){
        if(open==close && open==0){
            res.push_back(stackStr);
        return;
        }
        if(open>0){
            stackStr+='(';
            dfs(open-1,close,res,stackStr);
            stackStr.pop_back();
        }
        if(open<close){
            stackStr+=')';
            dfs(open,close-1,res,stackStr);
            stackStr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stackStr;
        dfs(n,n,res,stackStr);
    return res;
    }
};