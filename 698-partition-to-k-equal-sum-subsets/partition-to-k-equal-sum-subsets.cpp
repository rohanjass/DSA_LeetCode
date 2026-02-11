class Solution {
public:
    int sumTar;
    bool def(int i,int k,int target,vector<int>& nums,vector<bool>& used){
        if(k==0) return true;
        if(target==0) return def(nums.size()-1,k-1,sumTar,nums,used);

        for(int j=i;j>=0;j--){
            if(used[j] || target-nums[j]<0) continue;

            used[j]=true;
            if(def(j-1,k,target-nums[j],nums,used)) return true;
            used[j]=false;

            if(target==sumTar) break;
        }
    return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> used(n,false);
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%k!=0) return false;
        sumTar=sum/k;

    return def(n-1,k,sumTar,nums,used);
    }
};