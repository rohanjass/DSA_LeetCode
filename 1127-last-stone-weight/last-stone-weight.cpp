class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int cur=stones[stones.size()-1]-stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            if(cur>0){
                stones.push_back(cur);
            } else {
                stones.push_back(0);
            }
        }
    return stones[0];
    }
};