class Solution {
public:
    int findMax(vector<int>& arr){
        int maxi=INT_MIN;
        for(int n:arr){
            maxi=max(maxi,n);
        }
    return maxi;
    }
    long long totalHrs(vector<int>& piles,int hr){
        long long total=0;
        for(int n:piles){
            total+=ceil((double)(n)/(double)(hr));
        }
    return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hour=totalHrs(piles,mid);
            if(hour<=h) high=mid-1;
            else low=mid+1;
        }
    return low;
    }
};