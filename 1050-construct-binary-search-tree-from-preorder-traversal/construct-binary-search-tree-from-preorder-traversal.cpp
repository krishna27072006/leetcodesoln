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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);
        int i=1;
        int prev=preorder[0];
        TreeNode* node=root;
        while(i<preorder.size()){
            if(preorder[i]<prev){
                TreeNode* temp=new TreeNode(preorder[i]);
                st.top()->left=temp;
                st.push(temp);
                prev=preorder[i];
            }else{
                TreeNode* parent=NULL;
                while( !st.empty() && st.top()->val<preorder[i]){
                    parent=st.top();
                    st.pop();
                }
                TreeNode* temp=new TreeNode(preorder[i]);
                parent->right=temp;
                st.push(temp);
                prev=preorder[i];

            }
            i++;
        }
        return root;
    }
};