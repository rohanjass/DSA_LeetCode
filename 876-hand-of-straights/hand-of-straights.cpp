class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(int n:hand){
            if(mp[n]>0){
                for(int i=n;i<n+groupSize;i++){
                    if(mp[i]==0) return false;
                    mp[i]--;
                }
            }
        }
    return true;
    }
};