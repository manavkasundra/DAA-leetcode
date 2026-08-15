class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_set<char> chars(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // If either lowercase or uppercase is missing, split here
            if (!chars.count(tolower(c)) || !chars.count(toupper(c))) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                return left.size() >= right.size() ? left : right;
            }
        }
        
        return s; // all characters are "good" → whole string is nice
    }
};