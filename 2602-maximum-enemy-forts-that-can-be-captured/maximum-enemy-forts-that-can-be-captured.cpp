class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int j=-2;
        int res=0;
        for(int i=0;i<n;i++){
            if(forts[i]!=0){
                if(j!=-2 && forts[i]!=forts[j]){
                   res=max(res,i-j-1);
                }
                   j=i; 
            }
        }
    return res;
    }
};