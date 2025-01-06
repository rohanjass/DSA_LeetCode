class Solution {
public:
    int findMaxi(vector<int>& piles){
        int maxi=INT_MIN;
        for( int num:piles){
            maxi=max(maxi,num);
        }
    return maxi;
    }
    long long findHrs(vector<int>& piles,int hr){
        long long totalHrs=0;
        for(int pile:piles){
            totalHrs+=ceil((double)(pile)/(double)(hr));
        }
    return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMaxi(piles);
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            long long Hours=findHrs(piles,mid);
            if(Hours<=h) high=mid-1;
            else low=mid+1;
        }
    return low;
    }
};