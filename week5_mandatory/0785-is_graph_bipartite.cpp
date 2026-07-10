class Solution {
    bool ans=true;
public:
    void dfs(int i, bool c,vector<vector<int>>&grid,vector<bool>&vis,vector<bool>&col){
        for(int j=0;j<grid[i].size();j++){
            if(!ans){
                return;
            }

            int x=grid[i][j];
            if(!vis[x]){
                vis[x]=1;
                col[x]=!c;
                dfs(x,!c,grid,vis,col);
            } else if(!(c^col[x])){
                ans=false;
                return;
            } 
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>col(n),vis(n,false);

        for(int i=0;i<n;i++){
            if(!ans){
                return ans;
            }

            if(!vis[i]){
                col[i]=1;
                dfs(i,1,graph,vis,col);
            }
        }

        return ans;
    }
};
