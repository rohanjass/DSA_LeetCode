class Solution {
    public int longestOnes(int[] nums, int k) {
        int l=0,r=0;
        int maxLen=0;
        while(r<nums.length){
            if(nums[r]==0)k--;
            while(k<0){
                if(nums[l]==0) k++;
                l++;
            }
            maxLen=Math.max(maxLen,r-l+1);
            r++;
        }
    return maxLen;
    }
}