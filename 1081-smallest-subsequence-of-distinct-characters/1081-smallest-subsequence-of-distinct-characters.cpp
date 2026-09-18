class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> inResult(26, false);
        
        // Step 1: Record the last occurrence index of each character
        for (int i = 0; i < s.length(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        string result = ""; // Used as our monotonic stack
        
        // Step 2: Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            // If the character is already picked, skip it
            if (inResult[c - 'a']) {
                continue;
            }
            
            // Pop characters that are lexicographically larger than c
            // and appear again later in the string
            while (!result.empty() && result.back() > c && lastIndex[result.back() - 'a'] > i) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add current character
            result.push_back(c);
            inResult[c - 'a'] = true;
        }
        
        return result;
    }
};