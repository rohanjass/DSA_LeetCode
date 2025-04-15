class Solution {
public:
    int trap(vector<int>& height) {
        int lMax=0,rMax=0,l=0,r=height.size()-1,total=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(lMax>=height[l]) total+=lMax-height[l];
                else lMax=height[l];
            l++;
            }
            else{
                if(rMax>=height[r]) total+=rMax-height[r];
                else rMax=height[r];
            r--;
            }
        }
    return total;
    }
};