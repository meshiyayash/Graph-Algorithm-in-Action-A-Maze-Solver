class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&image,vector <vector<bool>>&vis,int color,int prim,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || image[i][j]!=prim){
            return;
        }

        vis[i][j]=1;
        image[i][j]=color;

        dfs(i+1,j,image,vis,color,prim,n,m);
        dfs(i-1,j,image,vis,color,prim,n,m);
        dfs(i,j-1,image,vis,color,prim,n,m);
        dfs(i,j+1,image,vis,color,prim,n,m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        dfs(sr,sc,image,vis,color,image[sr][sc],n,m);
        return image;
    }
};
