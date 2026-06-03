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
    void same(TreeNode* temp1,TreeNode* temp2,bool &check){
        if(temp1==NULL && temp2==NULL) return ;
         if(temp1==NULL || temp2==NULL) {
            check=false;
            return;
         }
         if(temp1->val != temp2->val){
            check=false;
            return;
         }
        

        same(temp1->left,temp2->left,check);
        same(temp1->right,temp2->right,check);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        bool check=true;
        same(p,q,check);
        return check;

    }
};