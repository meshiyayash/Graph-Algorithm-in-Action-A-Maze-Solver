class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        cost[0][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > p;
        p.push({0,{0,0}});
        
        vector<int> dir={0,1,0,-1,0};
        while(!p.empty()){
            int c = p.top().first;
            auto [i,j] = p.top().second;
            p.pop();

            if(c>cost[i][j]){
                continue;
            }

            for(int k=0;k<4;k++){
                int x=i+dir[k];
                int y=j+dir[k+1];
                
                if(x>=0 && x<m && y>=0 && y<n){
                    int newCost=max(cost[i][j],abs(heights[x][y]-heights[i][j]));
                    if(newCost<cost[x][y]){
                        cost[x][y] =newCost;
                        p.push({cost[x][y],{x,y}});
                    }
                }
            }
        }

        return cost[m-1][n-1];
    }
};
