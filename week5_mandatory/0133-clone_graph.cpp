/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* root=new Node(node->val);
        queue <Node*> q,n;
        q.push(node);
        n.push(root);
        unordered_map<Node*,Node*> vis;
        while(!q.empty()){
            Node*tmp = q.front();
            Node* cur= n.front();
            if(vis.find(tmp) == vis.end()){
                vis[tmp]=cur;
            }
            q.pop();
            n.pop();

            for(auto x: tmp->neighbors){
                if(vis.find(x)==vis.end()){
                    q.push(x);
                    Node* next=new Node(x->val);
                    cur->neighbors.push_back(next);
                    vis[x]=next;
                    n.push(next);
                } else {
                    cur->neighbors.push_back(vis[x]);
                }
            }
        }
        
        return root;
    }
};
