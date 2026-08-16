class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxEnding = 0, minEnding = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        
        for (int num : nums) {
            total += num;
            
            maxEnding = max(num, maxEnding + num);
            maxSum = max(maxSum, maxEnding);
            
            minEnding = min(num, minEnding + num);
            minSum = min(minSum, minEnding);
        }
        
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};