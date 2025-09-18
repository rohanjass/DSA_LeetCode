class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int maxTotal=total;
        for(int i=0;i<k;i++){
            total=total+cardPoints[n-i-1]-cardPoints[k-i-1];
            maxTotal=max(maxTotal,total);
        }
    return maxTotal;
    }
};