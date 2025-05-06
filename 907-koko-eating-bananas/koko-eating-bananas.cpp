class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        for(int p:piles){
            maxi=max(maxi,p);
        }
    return maxi;
    }
    long long findHrs(vector<int>& piles, int h){
        long long totalHrs=0;
        for(int p:piles){
            totalHrs+=ceil((double)(p)/(double)(h));
        }
    return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findMax(piles);
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            long long hrs=findHrs(piles,mid);
            if(hrs<=h) high=mid-1;
            else low=mid+1;
        }
    return low;
    }
};