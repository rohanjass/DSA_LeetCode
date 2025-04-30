class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for(int i=0;i<position.size();i++){
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        int fleets=1;
        double prevTime=(double)(target-pair[0].first)/pair[0].second;
        for(int i=0;i<position.size();i++){
            double curTime=(double)(target-pair[i].first)/pair[i].second;
            if(prevTime<curTime){
                fleets++;
                prevTime=curTime;
            } 
        }
    return fleets;
    }
};