class Solution {
    int preIndex = 0;
    unordered_map<int, int> inorderIndexMap;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a hash map to instantly find any node's index in the inorder array
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        // Start the recursive build using the full bounds of the inorder array
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        // Base case: If the start index passes the end index, there are no nodes left
        if (inStart > inEnd) return nullptr;
        
        // 1. Grab the root from preorder and move our pointer forward
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // 2. Find where this root splits the inorder array
        int mid = inorderIndexMap[rootVal];
        
        // 3. Recursively build the Left and Right subtrees
        // Everything to the left of 'mid' in inorder goes to the left child
        root->left = build(preorder, inStart, mid - 1);
        
        // Everything to the right of 'mid' in inorder goes to the right child
        root->right = build(preorder, mid + 1, inEnd);
        
        return root;
    }
};