class Solution {
public:
    int trap(vector<int>& height) {
        int rMax=0,lMax=0,total=0;
        int l=0,r=height.size()-1;
        while(l<=r){
            if(height[l]<=height[r]){
                if(lMax>=height[l]) total+=lMax-height[l];
                else lMax=height[l];
            l++;
            } else{
                if(rMax>=height[r]) total+=rMax-height[r];
                else rMax=height[r];
            r--;
            }
        }
    return total;
    }
};