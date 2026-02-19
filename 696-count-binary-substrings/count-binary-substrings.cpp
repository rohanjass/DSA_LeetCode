class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> cons;
        int n=s.size();
        int i=0;
        while(i<n){
            int num=0;
            if(s[i]=='0'){
                while(s[i]=='0'){
                    num++;
                    i++;
                }
            }
            else {
                while(s[i]=='1'){
                    num++;
                    i++;
                }
            }
        cons.push_back(num);
        }
        int res=0;
        for(int i=1;i<cons.size();i++){
                res+=min(cons[i],cons[i-1]);
            
        }
    return res;
    }
};