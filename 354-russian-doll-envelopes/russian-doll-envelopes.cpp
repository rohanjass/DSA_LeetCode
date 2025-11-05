class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(),envelopes.end(),comp);

        vector<int> res;
        for(auto& i:envelopes){
            res.push_back(i[1]);
        }

        vector<int> lis;
        lis.push_back(res[0]);

        for(int i=1;i<res.size();i++){
            if(res[i]>lis.back()){
                lis.push_back(res[i]);
            } else {
                int ind=lower_bound(lis.begin(),lis.end(),res[i])-lis.begin();
                lis[ind]=res[i];
            }
        }
    return lis.size();
    }
};