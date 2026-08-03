class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int totalElements = nums.size();
        int targetIndex = totalElements - k;
        return nums[targetIndex];
    }
};