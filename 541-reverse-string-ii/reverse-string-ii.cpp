class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        int n=s.size();
        int j=min(n,i+k);
        while(i<s.size()){
            reverse(s.begin()+i,s.begin()+j);
            i+=2*k;
            j=min(n,i+k);
        }
    return s;
    }
};