class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int cnt=1;
        res.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                cnt=1;
                res.push_back(s[i]);
            }
            else{
                cnt++;
                if(cnt<3){
                    res.push_back(s[i]);    
                }
            }
        }
    return res;
    }
};