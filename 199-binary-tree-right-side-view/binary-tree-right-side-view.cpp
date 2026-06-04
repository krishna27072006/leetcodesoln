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

 void level(TreeNode* root,int l,vector<int> &v){
    if(root==NULL) return;
    if(l==v.size()){
        v.push_back(root->val);
    }
    level(root->right,l+1,v);
    level(root->left,l+1,v);

 }
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        int l=0;
        level(root,l,v);
        return v;
        
        
    }
};