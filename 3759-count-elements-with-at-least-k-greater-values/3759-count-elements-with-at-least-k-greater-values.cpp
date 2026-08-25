class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0) return nums.size();

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int target = nums[n - k];

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < target) {
                count++;
            }
        }

        return count;
    }
};