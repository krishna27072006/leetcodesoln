/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void find_path(TreeNode* root,TreeNode*t,vector<TreeNode*> &v){
    v.push_back(root);
    if(root==t) return;
    if(root->left){
        find_path(root->left,t,v);
        if(t==v.back()){
            return;
        }
    }
    if(root->right){
        find_path(root->right,t,v);
        if(t==v.back()){
            return;
        }
    }
    v.pop_back();
 }
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp;
        vector<TreeNode*> qq;
        find_path(root,p,pp);
        find_path(root,q,qq);
        TreeNode* ans=NULL;
        int n = min(pp.size(), qq.size());

         for(int i = 0; i < n; i++) {
           if(pp[i] == qq[i])
              ans = pp[i];
               else
               break;
           }

return ans;


        
    }
};