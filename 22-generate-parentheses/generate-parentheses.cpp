class Solution {
public:
    void def(int open,int close,string& path,vector<string>& res){
        if(open==close && open==0){
            res.push_back(path);
        return;
        }

        if(open>0){
            path.push_back('(');
            def(open-1,close,path,res);
            path.pop_back();
        }
        if(open<close){
            path.push_back(')');
            def(open,close-1,path,res);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        def(n,n,path,res);

    return res;
    }
};