class Solution {
public:
    long long totalHours(vector<int>& piles,int h){
        long long total=0;
        for(int n:piles){
            total+=ceil((double)(n)/(double)(h));
        }
    return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int l=1,high=maxi;
        while(l<=high){
            int mid=l+(high-l)/2;
            long long hours=totalHours(piles,mid);
            if(hours<=h) high=mid-1;
            else l=mid+1;
        }
    return l;
    }
};