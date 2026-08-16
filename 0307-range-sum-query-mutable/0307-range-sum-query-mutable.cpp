class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 1, 0, n - 1);
    }
    
    void buildTree(vector<int>& nums, int treeIndex, int left, int right) {
        if (left == right) {
            tree[treeIndex] = nums[left];
            return;
        }
        
        int mid = left + (right - left) / 2;
        buildTree(nums, 2 * treeIndex, left, mid);
        buildTree(nums, 2 * treeIndex + 1, mid + 1, right);
        tree[treeIndex] = tree[2 * treeIndex] + tree[2 * treeIndex + 1];
    }

    void updateHelper(int treeIndex, int left, int right, int targetIndex, int newVal) {
        if (left == right) {
            tree[treeIndex] = newVal;
            return;
        }
        
        int mid = left + (right - left) / 2;
        
        if (targetIndex <= mid) {
            updateHelper(2 * treeIndex, left, mid, targetIndex, newVal);
        } else {
            updateHelper(2 * treeIndex + 1, mid + 1, right, targetIndex, newVal);
        }
        
        tree[treeIndex] = tree[2 * treeIndex] + tree[2 * treeIndex + 1];
    }
    
    void update(int index, int val) {
        updateHelper(1, 0, n - 1, index, val);
    }

    int queryHelper(int treeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) {
            return 0;
        }
        
        if (queryLeft <= left && right <= queryRight) {
            return tree[treeIndex];
        }
        
        int mid = left + (right - left) / 2;
        int leftSum = queryHelper(2 * treeIndex, left, mid, queryLeft, queryRight);
        int rightSum = queryHelper(2 * treeIndex + 1, mid + 1, right, queryLeft, queryRight);
        
        return leftSum + rightSum;
    }
    
    int sumRange(int left, int right) {
        return queryHelper(1, 0, n - 1, left, right);
    }
};