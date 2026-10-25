class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            
            // 1. Check for odd-length palindromes (center is at character i)
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;  // move left
                right++; // move right
            }
            
            // 2. Check for even-length palindromes (center is between i and i+1)
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;  // move left
                right++; // move right
            }
        }
        
        return count;
    }
};