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

void assin(vector<vector<int>> &v,int row,int col,TreeNode* root){
    if(root==NULL) return ;
    vector<int> p={col,row,root->val};
    v.push_back(p);
    assin(v,row+1,col-1,root->left);
    assin(v,row+1,col+1,root->right);
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        int row=0;
        int col=0;
        assin(v,row,col,root);
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int i=0;
        int n=v.size();
        while (i < n) {
            vector<int> p;
            int currCol = v[i][0];

            while (i < n && v[i][0] == currCol) {
                p.push_back(v[i][2]);
                i++;
            }

            ans.push_back(p);
        }

        return ans;
        
    }
};