class Solution {
    void dfs(vector<vector<int>>& isConnected,vector<bool>&vis,int i){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(isConnected,vis,j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                cnt++;
            }
        }

        return cnt;
    }
};
