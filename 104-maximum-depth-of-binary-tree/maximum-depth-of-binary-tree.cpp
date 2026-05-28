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

 void count(TreeNode* root,int ct,int &ans){
    ct++;
    if(root->left!=NULL&& root->right!=NULL){
      count(root->left,ct,ans);
      count(root->right,ct,ans);
    }else if(root->left!=NULL&& root->right==NULL){
        count(root->left,ct,ans);
    }else if(root->left==NULL&& root->right!=NULL){
        count(root->right,ct,ans);
    }else{
        ans=max(ans,ct);
        return;
    }
 }
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int ct=0;
        int ans=0;
        TreeNode* temp=root;
        count(root,ct,ans);
        return ans;
    }
};