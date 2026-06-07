/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void parentmap(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode*root){
    if(root==NULL){
        return;
    }
    
    if(root->left){
        parent[root->left]=root;
        parentmap(parent,root->left);

    }
    if(root->right){
        parent[root->right]=root;
        parentmap(parent,root->right);
    }

 }
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=NULL;
        parentmap(parent,root);
        unordered_map<TreeNode*,bool> visit;
        queue<TreeNode*> q;
        q.push(target);
        visit[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            dist ++;
            for(int i=0;i<n;++i){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visit[node->left]){
                    visit[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visit[node->right]){
                    visit[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visit[parent[node]]){
                    visit[parent[node]]=true;
                    q.push(parent[node]);
                }
            }


        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;



        
    }
};