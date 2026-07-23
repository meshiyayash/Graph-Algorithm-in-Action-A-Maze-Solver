#include<bits/stdc++.h>
using namespace std;


struct Grid { 
    int R, C;
    vector<string> cells; 
};

struct Result {
    int cost;                                  // total steps or total weight
    vector<pair<int,int>> path;                // cells in order
    int expanded;                              // cells visited by the search
};

struct Stats{
    // Stats to be calculated
    int bfsPairs =0;
    int dijkstraExpanded= 0;
    int astarExpanded=0;
    int dfsOrderings =0 ;
};

Stats maze_stats;
// Shared neighbour helper (no copy-paste across algorithms):
vector<pair<int,int>> neighbours(const Grid& g, int r, int c){
    vector<pair<int,int>> n;
    vector<int>dir = {0,1,0,-1,0};

    for(int i=0;i<4;i++){
        int x=r+dir[i];
        int y=c+dir[i+1];
        if(x>=0 && x<g.R && y>=0 && y<g.C && g.cells[x][y]!='#'){
            n.push_back({x,y});
        }
    }

    return n;
}

//Reconstruct path of exploration 
vector<pair<int,int>> reconstruct_path(const vector<vector<pair<int,int>>>&parent,pair<int,int> s,pair<int,int> t){
    pair<int,int> cur=t;
    vector<pair<int,int>> path;

    while(cur!=s){
        path.push_back(cur);
        cur=parent[cur.first][cur.second];
    }
    
    path.push_back(s);

    reverse(path.begin(),path.end());

    return path;
}

// Single-pair shortest path — implement all four:
Result bfs      (const Grid& g, pair<int,int> s, pair<int,int> t){
    Result search;
    search.cost=0;
    vector<vector<pair<int,int>>> parent(g.R,vector<pair<int,int>>(g.C,{-1,-1}));

    vector<vector<bool>> vis(g.R,vector<bool>(g.C,false));
    queue<pair<int,int>>q;
    q.push(s);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            if(q.front()==t){
                search.path = reconstruct_path(parent,s,t);
                return search;
            }
            int i=q.front().first;
            int j=q.front().second;
            vis[i][j]=true;
            q.pop();

            for(auto n:neighbours(g,i,j)){
                if(!vis[n.first][n.second]){
                    vis[n.first][n.second]=true;
                    parent[n.first][n.second]={i,j};
                    q.push(n);
                }
            }
        }
        search.cost++;
    }

    search.path=reconstruct_path(parent,s,t);
    return search;
}


// Result dfsPath  (const Grid& g, pair<int,int> s, pair<int,int> t);
int cellcost(char ch){
    if(ch>='0' && ch<='9'){
        return ch - '0';
    }

    return 1;
}
Result dijkstra (const Grid& g, pair<int,int> s, pair<int,int> t){
    Result ans;
    ans.cost=0;
    ans.expanded=0;
    vector<vector<pair<int,int>>> parent(g.R,vector<pair<int,int>>(g.C,{-1,-1}));

    vector<vector<int>> dist(g.R,vector<int>(g.C,INT_MAX));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int ,pair<int,int>>> > p;
    p.push({0,{s.first,s.second}});
    dist[s.first][s.second]=0;

    while(!p.empty()){
        auto [cost,pos] = p.top();
        int i=pos.first;
        int j=pos.second;
        p.pop();

        if(cost>dist[i][j]){
            continue;
        }

        ans.expanded++;

        if(pos==t){
            break;
        }
        for(auto n:neighbours(g,i,j)){
            int x=n.first;
            int y=n.second;
            
            int d=cost+cellcost(g.cells[x][y]);

            if(d<dist[x][y]){
                dist[x][y]=d;
                parent[x][y]={i,j};
                p.push({d,n});
            }
        }
    }

    ans.cost=dist[t.first][t.second];
    ans.path=reconstruct_path(parent,s,t);
    return ans;
}

//Defining heuristic function to be used in A*
int heuristic(pair<int,int>s,pair<int,int>t){
    return abs(s.first-t.first)+abs(s.second-t.second);
}

Result astar    (const Grid& g, pair<int,int> s, pair<int,int> t){
    Result ans;
    ans.cost=0;
    ans.expanded=0;

    vector<vector<pair<int,int>>> parent(g.R,vector<pair<int,int>>(g.C,{-1,-1}));

    vector<vector<int>> dist(g.R,vector<int>(g.C,INT_MAX));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int ,pair<int,int>>> > p;
    p.push({heuristic(s,t),s});
    dist[s.first][s.second]=0;

    while(!p.empty()){
        auto [cost,pos] = p.top();
        int i=pos.first;
        int j=pos.second;
        p.pop();

        
        if(cost!=dist[i][j]+heuristic(pos,t)){
            continue;
        }

        ans.expanded++;

        if(pos==t){
            break;
        }
        for(auto n:neighbours(g,i,j)){
            int x=n.first;
            int y=n.second;
            
            int d=dist[i][j]+cellcost(g.cells[x][y]);

            if(d<dist[x][y]){
                dist[x][y]=d;
                parent[x][y]={i,j};
                p.push({d+heuristic(n,t),n});
            }
        }
    }

    ans.cost=dist[t.first][t.second];
    ans.path=reconstruct_path(parent,s,t);
    return ans;

}

void shortest(const vector<vector<int>>& dist,vector<int>&indx,int&cur_cost,int &best,vector<bool>&vis,vector<int>& outOrder){
// base case ---> if i have visited all the index from start then I should go to the goal
    if(indx.size() == vis.size()){
        maze_stats.dfsOrderings++;
        cur_cost+=dist[indx.back()][dist.size()-1];
        indx.push_back(dist.size()-1);
        if(cur_cost<best){
            best=cur_cost;
            outOrder=indx;
        }
        indx.pop_back();
        cur_cost-=dist[indx.back()][dist.size()-1];
        return;
    }

// Pruning step ---> IF at any moment my current distance is greater than best I should avoid that path
    if(cur_cost>=best){
        return;
    }
// Recursively visiting each coin and finding minimum cost/distance
    for(int i=1;i+1<=vis.size();i++){
        if(vis[i]){
            continue;
        }

        cur_cost+=dist[indx.back()][i];
        vis[i]=true;
        indx.push_back(i);
        shortest(dist,indx,cur_cost,best,vis,outOrder);

        //backtracing
        indx.pop_back();
        cur_cost-=dist[indx.back()][i];
        vis[i]=false;
    }
}

// Coin-order backtracking:
int bestOrder(const vector<vector<int>>& dist,int startIdx, int goalIdx, vector<int>& outOrder){
    int best=INT_MAX ,cur_cost=0;

    vector<bool> vis(dist.size()-1,false);
    vis[0]=true;

    vector<int> indx;
    indx.push_back(0);
    shortest(dist,indx,cur_cost,best,vis,outOrder);
    
    return best;
}


void printPath(vector<string> g,const vector<pair<int,int>>&walk){
    for(auto indx:walk){
        if(g[indx.first][indx.second] != 'G'&&g[indx.first][indx.second] != 'S' && g[indx.first][indx.second] != 'c'){
            g[indx.first][indx.second]='*';
        }
    }

    for(int i=0;i<g.size();i++){
        cout << g[i] << endl;
    }
}

void printCoinOrder(const vector<pair<int,int>>& a,const vector<int>& order){
    cout << "S -> ";
    for(int i=1;i+1<order.size();i++){
        cout<< "c(" << a[order[i]].first << "," << a[order[i]].second << ") -> ";
    } 
    cout << "G\n";
}

int main(int argc,char* argv[]){
    if(argc != 2){
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }
    ifstream fin(argv[1]);

// Initialising grid and taking input    
    Grid g;
    pair<int,int> start,goal;

    fin >> g.R >> g.C;
    fin >> start.first >> start.second;
    fin >> goal.first >> goal.second;

// storing the graph 

    for(int i=0;i<g.R;i++){
        string s;
        fin >> s;
        g.cells.push_back(s);
    }

// Storing the key points
    vector<pair<int,int >> keypoints;
    int total_keypoints;
    keypoints.push_back(start);

    for(int i=0;i<g.R;i++){
        for(int j=0;j<g.C;j++){
            if(g.cells[i][j]=='c'){
                keypoints.push_back({i,j});
            }
        }
    }

    keypoints.push_back(goal);
    total_keypoints=keypoints.size();
// K+2 * K+2 matrix for storing min distance between each key point
    vector<vector<int>> bfs_matrix(total_keypoints,vector<int>(total_keypoints,0));

    for(int i=0;i<total_keypoints;i++){
        bfs_matrix[i][i]=0;
        for(int j=i+1;j<total_keypoints;j++){
            maze_stats.bfsPairs++;
            bfs_matrix[i][j]=bfs(g,keypoints[i],keypoints[j]).cost;
            bfs_matrix[j][i]=bfs_matrix[i][j];
        }
    }

// Finding best path for non weighted graphs
    vector <int> non_weighted_path;
    int non_weighted_path_length=bestOrder(bfs_matrix,0,total_keypoints-1,non_weighted_path);


// K+2 * K+2 matrix for storing min distance between each key point in a weighted graph
    vector<vector<int>> dijkstra_matrix(total_keypoints,vector<int>(total_keypoints,0));
    for(int i=0;i<total_keypoints;i++){
        dijkstra_matrix[i][i]=0;
        for(int j=i+1;j<total_keypoints;j++){
            Result r= dijkstra(g,keypoints[i],keypoints[j]);
            dijkstra_matrix[i][j]=r.cost;
            dijkstra_matrix[j][i]=dijkstra_matrix[i][j];

            maze_stats.dijkstraExpanded+=r.expanded;
        }
    }

// Finding best path for weighted graphs
    vector<int> weighted_path;
    int weighted_path_length=bestOrder(dijkstra_matrix,0,total_keypoints-1,weighted_path);

// K+2 * K+2 matrix for A* search
    vector<vector<int>> astar_matrix(total_keypoints,vector<int>(total_keypoints,0));
    for(int i=0;i<total_keypoints;i++){
        astar_matrix[i][i]=0;
        for(int j=i+1;j<total_keypoints;j++){
            Result r= astar(g,keypoints[i],keypoints[j]);
            astar_matrix[i][j]=r.cost;
            astar_matrix[j][i]=astar_matrix[i][j];

            maze_stats.astarExpanded+=r.expanded;
        }
    }

//Storing the full path of the walk;
vector<pair<int,int>> walk;
for(int i=0;i+1<non_weighted_path.size();i++){
    Result r=bfs(g,keypoints[non_weighted_path[i]],keypoints[non_weighted_path[i+1]]);

    for(auto i:r.path){
        walk.push_back(i);
    }
    walk.pop_back();
}
walk.push_back(goal);

printPath(g.cells,walk);
printCoinOrder(keypoints,weighted_path);
    return 0;
}