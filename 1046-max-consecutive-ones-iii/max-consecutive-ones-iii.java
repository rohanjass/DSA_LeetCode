class Solution {
    public int longestOnes(int[] nums, int k) {
        int i=0;
        int j=0;
        int maxi=0;
        while(j<nums.length){
            if(nums[j]==0)k--;
            while(k<0){
                if(nums[i]==0)k++;
                i++;
            }
            maxi=Math.max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
}   