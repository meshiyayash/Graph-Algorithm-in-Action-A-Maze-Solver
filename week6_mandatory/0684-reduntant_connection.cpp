class DSU{
    vector<int> par;
    vector<int> rank;

public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=1;
        }
    }

    int find(int n){
        if(par[n]==n){
            return n;
        }

        int x=find(par[n]);
        par[n]=x;
        return x;        
    }

    void Union(int a,int b){
        int pa=find(a);
        int pb=find(b);

        if(pa==pb){
            return;
        }

        if(rank[pa]==rank[pb]){
            par[pb]=pa;
            rank[pa]++;
        } else if(rank[pa]>rank[pb]){
            par[pb]=pa;
        } else {
            par[pa]=pb;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n);

        for(auto i:edges){
            if(d.find(i[1])==d.find(i[0])){
                return i;
            } else {
                d.Union(i[1],i[0]);
            }
        }

        return vector<int>{};
    }
};
