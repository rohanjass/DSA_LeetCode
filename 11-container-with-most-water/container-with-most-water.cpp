class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int res=0,area=0;
        while(l<=r){
            area=min(height[l],height[r]) *(r-l);
            res=max(res,area);
            if(height[l]<=height[r]){
                l++;
            } else {
                r--;
            }
        }
    return res;
    }
};