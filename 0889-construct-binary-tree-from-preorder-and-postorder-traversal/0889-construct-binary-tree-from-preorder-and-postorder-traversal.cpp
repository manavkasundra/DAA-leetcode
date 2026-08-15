class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(preorder, postorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* solve(vector<int>& pre, vector<int>& post, 
                    int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        
        if (preStart == preEnd) {
            return new TreeNode(pre[preStart]);
        }
        
        TreeNode* root = new TreeNode(pre[preStart]);
        
        int leftRootVal = pre[preStart + 1];
        
        int leftCount = 0;
        for (int i = postStart; i <= postEnd; i++) {
            leftCount++;
            if (post[i] == leftRootVal) {
                break;
            }
        }
        
        root->left = solve(pre, post, 
                          preStart + 1, preStart + leftCount,
                          postStart, postStart + leftCount - 1);
        
        root->right = solve(pre, post,
                           preStart + leftCount + 1, preEnd,
                           postStart + leftCount, postEnd - 1);
        
        return root;
    }
};