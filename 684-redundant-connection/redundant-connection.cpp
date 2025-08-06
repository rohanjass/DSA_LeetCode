class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1),rank(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;//self parent mapping
        }
        for(const auto& edge:edges){
            if(!unionFind(par,rank,edge[0],edge[1])) return {edge[0],edge[1]};
        }
    return {};
    }

    int find(vector<int>& par,int n){
        int p=par[n];
        while(p!=par[p]){
            par[p]=par[par[p]];
            p=par[p];
        }
    return p;
    }

    bool unionFind(vector<int>& par,vector<int>& rank,int n1 ,int n2){
        int p1=find(par,n1);
        int p2=find(par,n2);

        if(p1==p2) return false;
        else if(rank[p1]>=rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        } else{
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
    return true;
    }
};