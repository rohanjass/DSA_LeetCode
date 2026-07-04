class Solution {
public:
    vector<int> par,rank;
    int find(int p){
        if(par[p]==p){
            return p;
        }
    return par[p]=find(par[p]);
    }
    void Union(int n1,int n2){
        int p1=find(n1);
        int p2=find(n2);

        if(p1==p2) return;
        if(rank[p1]>=rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else if(rank[p2]>rank[p1]){
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n+1);
        rank.assign(n+1,1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(auto& road:roads){
            Union(road[0],road[1]);
        }
        int root=find(1);
        int res=INT_MAX;
        for(auto& road:roads){
            if(find(road[1])==root){
                res=min(res,road[2]);
            }
        }
    return res;   
    }
};