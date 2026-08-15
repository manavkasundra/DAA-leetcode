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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        getInorder(root, sortedValues);
        return buildBalancedTree(sortedValues, 0, sortedValues.size() - 1);
    }
    
    void getInorder(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;
        
        getInorder(root->left, values);
        values.push_back(root->val);
        getInorder(root->right, values);
    }
    
    TreeNode* buildBalancedTree(vector<int>& values, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        
        root->left = buildBalancedTree(values, start, mid - 1);
        root->right = buildBalancedTree(values, mid + 1, end);
        
        return root;
    }
};