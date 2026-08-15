class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Sort the numbers from largest to smallest using a simple inline rule
        sort(nums.begin(), nums.end(), [](string& a, string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length(); // Rule 1: Longer string is bigger
            }
            return a > b; // Rule 2: If lengths are equal, compare digit by digit
        });
        
        // Since the array is now sorted largest to smallest, 
        // the kth largest is at index k - 1
        return nums[k - 1];
    }
};