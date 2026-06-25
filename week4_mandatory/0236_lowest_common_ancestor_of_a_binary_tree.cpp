/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <vector>
class Solution {
public:
    bool solve(TreeNode* root,int target, vector<TreeNode*> &path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root->val==target){
            return true;
        }
        if((solve(root->left,target,path))|| (solve(root->right,target,path))){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1 = p->val;
        int n2= q->val;
        vector<TreeNode*> path1,path2;
        solve(root,n1,path1);
        solve(root,n2,path2);
        TreeNode* ans =NULL;
        int i=0;
        while(i<path1.size() && i<path2.size() && path1[i]==path2[i]){
            ans = path1[i];
            i++;
        }
        return ans;
    }
};
