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
 void preorder(vector<TreeNode*> &v,TreeNode* root){
    if(root==NULL){
        return;
    }
    v.push_back(root);
    preorder(v,root->left);
    preorder(v,root->right);
 }
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> v;
        preorder(v,root);
        TreeNode* temp=root;
        for(int i=1;i<v.size();++i){
            temp->left=NULL;
            temp->right=v[i];
            temp=temp->right;  
        }
        temp->right=NULL;
        temp->left=NULL;
        
        
    }
};