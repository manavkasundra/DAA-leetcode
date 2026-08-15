class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        
        int maxNum = nums[0];
        int maxPos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxPos = i;
            }
        }
        
        TreeNode* root = new TreeNode(maxNum);
        
        vector<int> leftNums;
        vector<int> rightNums;
        
        for (int i = 0; i < maxPos; i++) {
            leftNums.push_back(nums[i]);
        }
        
        for (int i = maxPos + 1; i < nums.size(); i++) {
            rightNums.push_back(nums[i]);
        }
        
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        
        return root;
    }
};