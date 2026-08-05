class Solution {
public:
    long long totalTime(vector<int>& piles,int rate){
        long long total_time=0;
        for(int n:piles){
            total_time+=ceil((double)n/(double)rate);
        }
    return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long curTime=totalTime(piles,mid);
            if(curTime<=h) high=mid-1;
            else low=mid+1;
        }
    return low;
    }
};