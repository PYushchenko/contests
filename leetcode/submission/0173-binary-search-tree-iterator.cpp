/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> st;
    
    BSTIterator(TreeNode* root) {
        auto p = root;
        while (p) {
            st.push(p);
            p = p->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto top = st.top();
        st.pop();
        if (top->right) {
            auto p = top->right;
            while (p) {
                st.push(p);
                p = p->left;
            }
        }
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
