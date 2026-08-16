class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        
        for(int start = 0; start < n; start++) {
            unordered_set<int> evens, odds;
            
            for(int end = start; end < n; end++) {
                if(nums[end] % 2 == 0) {
                    evens.insert(nums[end]);
                } else {
                    odds.insert(nums[end]);
                }
                
                if(evens.size() == odds.size()) {
                    int length = end - start + 1;
                    maxLength = max(maxLength, length);
                }
            }
        }
        
        return maxLength;
    }
};