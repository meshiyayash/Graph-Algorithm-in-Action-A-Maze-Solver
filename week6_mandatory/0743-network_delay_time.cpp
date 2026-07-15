class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto i: times){
            g[i[0]].push_back({i[1],i[2]});
        }

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> > q;
        q.push({0,k});

        while(!q.empty()){
            int u=q.top().second;
            int d=q.top().first;
            q.pop();

            if(d>dis[u]){
                continue;
            }
            for(auto i:g[u]){
                if(dis[i.first] > dis[u] + i.second){
                    dis[i.first]=dis[u] + i.second;
                    q.push({dis[i.first],i.first});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(dis[i],ans);
        }

        if(ans==INT_MAX){
            return -1;
        } else {
            return ans;
        }
    }
};
