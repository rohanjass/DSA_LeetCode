class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> freqMap=new HashMap<>();
        for(int n:nums){
            freqMap.put(n,freqMap.getOrDefault(n,0)+1);
        }

        List<Integer>[] arr= new List[nums.length+1];

        for(int key:freqMap.keySet()){
            int freq=freqMap.get(key);
            if(arr[freq]==null){
                arr[freq]=new ArrayList<>();
            }
            arr[freq].add(key);
        }

        List<Integer> res=new ArrayList<>();
        for(int i=arr.length-1;i>=0;i--){
            if(arr[i]!=null && res.size()<k){
                res.addAll(arr[i]);
            }
        }
        int[] result=new int[k];
        for(int i=0;i<k;i++){
            result[i]=res.get(i);
        }
    return result;
    }
}