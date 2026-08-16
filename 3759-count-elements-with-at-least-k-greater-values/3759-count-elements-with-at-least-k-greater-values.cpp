class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (k == 0) {
            return n;
        }
        
        int threshold = nums[n - k];
        int count = 0;
        for (int x : nums) {
            if (x < threshold) count++;
        }
        return count;
    }
};