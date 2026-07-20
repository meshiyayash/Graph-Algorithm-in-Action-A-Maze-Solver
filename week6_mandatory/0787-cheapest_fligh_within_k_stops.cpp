class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>> > g(n);

        for(auto f:flights){
            g[f[0]].push_back({f[1],f[2]});
        }

        vector<int> dis(n,INT_MAX);
        dis[src]=0;

        queue<pair<int,int>>q;
        q.push({src,dis[src]});

        while(!q.empty() && k>=0){
            int sz=q.size();
            while(sz--){
                int u=q.front().first;
                int cost=q.front().second;
                q.pop();
                
                
                for(auto v:g[u]){
                    int newCost = v.second + cost;
                    if(dis[v.first] > newCost){
                        dis[v.first]=newCost;
                        q.push({v.first,dis[v.first]});    
                    }                
                }
            }
            k--;
        }

        if(dis[dst] == INT_MAX){
            return -1;
        } else {
            return dis[dst];
        }
    }

};
