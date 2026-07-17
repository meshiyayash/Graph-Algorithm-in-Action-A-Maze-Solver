class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> vis(n,0);
        unordered_set<int> s;
        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
        q.push({0,0});
        int ans=0;

        while(!q.empty()){
            auto [c,u]= q.top();
            q.pop();
            if(s.find(u)!=s.end()){
                continue;
            }

            s.insert(u);
            vis[u]=1;
            ans+=c; 
            for(int i=0;i<n;i++){
                if(vis[i]){
                    continue;
                }
                int dis=abs(points[i][0]-points[u][0]) + abs(points[i][1]-points[u][1]);
                q.push({dis,i});
            }
        }

        return ans;
    }
};
