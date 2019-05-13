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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        if (root == NULL) {
            return "nil ";
        }
        ss << root->val << " " << serialize(root->left) << serialize(root->right);
        return ss.str();
    }

    TreeNode* deserialize(stringstream &ss) {
        string x;
        ss >> x;
        if (x == "nil") {
            return NULL;
        } else {
            int t = atoi(x.c_str());
            TreeNode * n = new TreeNode(t);
            n->left = deserialize(ss);
            n->right = deserialize(ss);
            return n;
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss = stringstream(data);
        return deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
