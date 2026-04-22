class Solution {
public:
    bool canShip(vector<int>& weights, int days,int cap){
        int d=1,load=0;
        for(int w:weights){
            if(load+w>cap){
                load=w;
                d++;
            } else {
                load+=w;
            }
        }
    return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);

        while(l<=h){
            int mid=l+(h-l)/2;

            if(canShip(weights,days,mid)){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
    return l;
    }
};