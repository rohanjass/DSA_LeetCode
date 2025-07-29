class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int maxSum=total;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            total=total+cardPoints[n-i-1]-cardPoints[k-i-1];
            maxSum=max(maxSum,total);
        }
    return maxSum;
    }
};