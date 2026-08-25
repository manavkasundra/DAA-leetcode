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
    TreeNode* build(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe) {
        if (is > ie || ps > pe) return NULL;

        TreeNode* root = new TreeNode(post[pe]);

        int k = is;
        while (in[k] != root->val) k++;

        int left = k - is;

        root->left = build(in, is, k - 1, post, ps, ps + left - 1);
        root->right = build(in, k + 1, ie, post, ps + left, pe - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};