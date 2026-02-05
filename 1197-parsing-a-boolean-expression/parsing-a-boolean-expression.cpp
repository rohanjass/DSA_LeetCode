class Solution {
public:
    bool parse(int& i,string& s ,vector<int>& dp){
          int start = i;               // store starting index

        if (dp[start] != -1) return dp[start];
        if(dp[i]!=-1) return dp[i];
        bool res;

        if(s[i]=='t'){
            res=true;
            i++;
        } else if(s[i]=='f'){
            res=false;
            i++;
        }

        else if(s[i]=='!'){
            i+=2;
            bool val=parse(i,s,dp);
            res=!val;
            i++;
        } else {
            char op=s[i];
            i+=2;
            res=(op=='&');
            while(true){
                bool val=parse(i,s,dp);
                if(op=='&') res &=val;
                else res |=val;

                if(s[i]==')'){
                    i++;
                    break;
                }
                i++;
            }
        }
    return dp[start]=res;
    }
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        vector<int> dp(n,-1);
        int i=0;
        return parse(i,expression,dp);
    }
};