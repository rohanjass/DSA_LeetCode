class Solution {
public:
    int find(vector<int>& par,int n){
        if(par[n]!=n){
            par[n]=find(par,par[n]);
        }
    return par[n];
    }
    bool unionFind(int n1,int n2,vector<int>& par,vector<int>& rank){
        int p1=find(par,n1);
        int p2=find(par,n2);
        if(p1==p2){
            return true;
        }
        if(rank[p1]>rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        } else {
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
    return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n+1,1),par(n+1);
        for(int i=1;i<n+1;i++){
            par[i]=i;
        }
        for(auto& e:edges){
            if(unionFind(e[0],e[1],par,rank)) return {e[0],e[1]};
        }
    return {};
    }
};