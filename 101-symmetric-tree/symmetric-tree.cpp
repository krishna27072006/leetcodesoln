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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        while(!q.empty()){
            vector<int> p;
            int n=q.size();
            for(int i=0;i<n;++i){
                TreeNode* node=q.front();
                q.pop();
                if(node == nullptr){
                    p.push_back(INT_MIN);
                    continue;
                }
                p.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            v.push_back(p);
        }
        for(int i=1;i<v.size();++i){
            if(v[i].size()%2!=0){
                return false;
            }else{
                int n=v[i].size();
                for(int j=0;j<(n/2);++j){
                    if(v[i][j]!=v[i][n-1-j]){
                        return false;
                    }
                }
            }
        }
        return true;  
    }
};