class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                check.push(s[i]);
            }
            
            else {
                if(check.empty()||(s[i]==')'&& check.top()!='(')|| (s[i]==']'&& check.top()!='[') || (s[i]=='}'&& check.top()!='{')) return false;
            check.pop();
            }
        }
        
        return check.empty();
    }
};