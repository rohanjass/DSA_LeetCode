class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void def(int i,int j,int tar,vector<vector<int>>& image,int color){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=tar) return;
        image[i][j]=color;
        for(auto& d:dir){
            int nr=i+d.first;
            int nc=j+d.second;
            def(nr,nc,tar,image,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        def(sr,sc,image[sr][sc],image,color);
        return image;
    }
};