class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int area=0,maxArea=0;
        while(l<r){
            area=(r-l)*min(height[l],height[r]);
            maxArea=max(maxArea,area);
            if(height[l]<=height[r]){
                l++;
            } else{
                r--;
            }
        }
    return maxArea;
    }
};