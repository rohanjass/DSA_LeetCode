class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n=nums.length;
        int max=n/3;
        List<Integer> res=new ArrayList();
        int count=1;
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
            if(nums[i]==nums[i-1]){
                count++;
            } else{
                if(count>max){
                    res.add(nums[i-1]);
                }
                count=1;
            }
        }
        if(count>max){
            res.add(nums[nums.length-1]);
        }
    return res;
    }
}