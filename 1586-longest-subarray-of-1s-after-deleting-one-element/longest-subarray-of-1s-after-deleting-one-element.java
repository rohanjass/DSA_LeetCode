class Solution {
    public int longestSubarray(int[] nums) {
        int l=0,r=0;
        int maxLen=0;
        int k=0;
        while(r<nums.length){
            if(nums[r]==0) k++;
            while(k>1){
                if(nums[l]==0) k--;
                l++;
            }
            maxLen=Math.max(maxLen,r-l);
            r++;
        }
    return maxLen;
    }
}