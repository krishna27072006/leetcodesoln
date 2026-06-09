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

 void traverse(TreeNode* root,vector<int> &v){
    if(root==NULL) return;
    v.push_back(root->val);
    traverse(root->left,v);
    traverse(root->right,v);
}
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> v;
        traverse(root,v);
        return v.size();
        
    }
};