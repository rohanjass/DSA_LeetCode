class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int i=0,j=0,maxC=0;
        while(j<nums.length){
            if(nums[j]==1){
                maxC=Math.max(maxC,j-i+1);
                j++;
            } else if(nums[j]==0){
                j++;
                i=j;
            }
        }
    return maxC;
    }
}