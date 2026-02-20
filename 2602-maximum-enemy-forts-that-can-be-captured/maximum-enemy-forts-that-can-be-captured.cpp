class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int prev=-1;
        int maxForts=0;
        for(int i=0;i<n;i++){
            if(forts[i]!=0){
                if(prev!=-1 && forts[prev]!=forts[i]){
                    maxForts=max(maxForts,i-prev-1);
                }
                prev=i;
            }
        }
    return maxForts;
    }
};