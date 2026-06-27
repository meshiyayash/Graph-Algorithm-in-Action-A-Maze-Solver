/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode*root,int&ans){
        if(root==NULL){
            return 0;
        }
        int a=depth(root->left,ans);
        int b=depth(root->right,ans);
        ans=max(ans,a+b);
        return max(a,b)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int x=depth(root,ans);
        return ans;
    }
};
