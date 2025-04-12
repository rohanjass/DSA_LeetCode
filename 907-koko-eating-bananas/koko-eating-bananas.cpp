class Solution {
public:
    int maxi(vector<int>& piles){
        int maxE=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxE=max(maxE,piles[i]);
        }
    return maxE;
    }
    long long findHrs(vector<int>& piles,int h){
        long long totalHrs=0;
        for(int i=0;i<piles.size();i++){
            totalHrs+=ceil((double)(piles[i])/(double)(h));
        }
    return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxi(piles);
        int mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            long long hours=findHrs(piles,mid);
            if(hours<=h)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};