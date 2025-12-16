class Solution {
public:
    int findPar(int n,vector<int>& par){
        if(par[n]!=n){
            par[n]=findPar(par[n],par);
        }
    return par[n];
    }

    bool unionFind(int n1,int n2,vector<int>& par,vector<int>& rank){
        int p1=findPar(n1,par);
        int p2=findPar(n2,par);

        if(p1==p2){
            return false;
        }
        if(rank[p1]>=rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        } else{
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
    return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int> par(n+1),rank(n+1,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        for(auto const& e:edges){
            if(!unionFind(e[0],e[1],par,rank)) return {e[0],e[1]};
        }
    return {};
    }
};