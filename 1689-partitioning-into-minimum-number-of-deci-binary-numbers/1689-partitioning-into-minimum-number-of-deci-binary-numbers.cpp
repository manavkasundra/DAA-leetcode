class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        
        // Look at every character in the string
        for (int i = 0; i < n.length(); i++) {
            // Convert the character to an actual integer (e.g., '3' becomes 3)
            int current_digit = n[i] - '0'; 
            
            // Keep track of the largest digit we find
            if (current_digit > max_digit) {
                max_digit = current_digit;
            }
        }
        
        return max_digit;
    }
};