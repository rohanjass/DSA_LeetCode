class Solution {
public:
    static bool comp(const vector<int>& a ,const vector<int>& b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int a=INT_MIN,b=INT_MIN;
        int res=0;
        for(auto& it:intervals){
            int st=it[0];
            int end=it[1];
            bool aIn=(st<=a && a<=end);
            bool bIn=(st<=b && b<=end);
            if(aIn && bIn){
                continue;
            } else if(aIn || bIn){
                res+=1;
                a=b;
                b=end;
            } else {
                res+=2;
                a=end-1;
                b=end;
            }
        }
    return res;
    }
};