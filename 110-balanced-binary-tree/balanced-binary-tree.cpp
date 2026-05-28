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
    if(root==NULL) return;   // added

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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int ct=0, ans=0;
        count(root->left,ct,ans);

        int ct1=0, ans1=0;
        count(root->right,ct1,ans1);

        if(abs(ans-ans1)>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};