class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res=0;
        for(int num:nums){
            if(!mp[num]){
                mp[num]=mp[num-1]+mp[num+1]+1;
                mp[num-mp[num-1]]=mp[num];//left boundry starting of sequence
                mp[num+mp[num+1]]=mp[num];//right boundry ending of sequence
                res=max(res,mp[num]);
            }
        }
    return res;
    }
};