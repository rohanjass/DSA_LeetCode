class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost=nums[0];
        sort(nums.begin()+1,nums.end());
        for(int i=1;i<=2;i++){
            cost+=nums[i];
        }
    return cost;
    }
};