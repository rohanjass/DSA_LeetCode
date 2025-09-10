class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr=startPos[0],sc=startPos[1];
        int hr=homePos[0],hc=homePos[1];
        int cost=0;
        if(sr<hr){
            for(int i=sr+1;i<=hr;i++) cost+=rowCosts[i];
        } else {
            for(int i=sr-1;i>=hr;i--) cost+=rowCosts[i];
        }

        if(sc<hc){
            for(int i=sc+1;i<=hc;i++) cost+=colCosts[i];
        } else {
            for(int i=sc-1;i>=hc;i--) cost+=colCosts[i];
        }
    return cost;
    }
};