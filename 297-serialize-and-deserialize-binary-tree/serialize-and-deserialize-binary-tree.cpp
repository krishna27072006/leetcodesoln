/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "NULL,";
            }
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<string> tokens;
        string temp;

        for (char ch : data) {
            if (ch == ',') {
                tokens.push_back(temp);
                temp.clear();
            } else {
                temp += ch;
            }
        }

        if (tokens.empty() || tokens[0] == "NULL")
            return NULL;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < tokens.size() && tokens[i] != "NULL") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            if (i < tokens.size() && tokens[i] != "NULL") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

