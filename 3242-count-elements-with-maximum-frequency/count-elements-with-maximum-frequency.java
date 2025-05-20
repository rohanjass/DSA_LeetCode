class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer,Integer>freqMap=new HashMap<>();
        int maxFreq=0;
        int total=0;
        for(int num:nums){
            int freq=0;
            if(freqMap.containsKey(num)){
                freq=freqMap.get(num);
            }
            freqMap.put(num, freq + 1);
            maxFreq=Math.max(maxFreq,freq+1);
        }
        for(int f:freqMap.values()){
            if(f==maxFreq) total+=f;
        }
    return total;
    }
}