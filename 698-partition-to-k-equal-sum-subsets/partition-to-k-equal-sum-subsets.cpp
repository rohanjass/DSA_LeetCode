class Solution {
public:
    int sumTarget;
    bool def(int i,int k,int target,vector<int>& nums,vector<bool>& used){
        if(k==0) return true;
        if(target==0) return def(nums.size()-1,k-1,sumTarget,nums,used);

        for(int j=i;j>=0;j--){
            if(used[j] || target-nums[j]<0){
                continue;
            }

            used[j]=true;

            if(def(j-1,k,target-nums[j],nums,used)) return true;

            used[j]=false;
        }
    return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%k!=0) return false;
        sumTarget=sum/k;
        vector<bool> used(nums.size(),false);
        return def(nums.size()-1,k,sumTarget,nums,used);
    }
};