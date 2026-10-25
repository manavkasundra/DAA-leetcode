class Solution {
public:
    int minOperations(int n) {
        int operations = 0;
        
        while (n > 0) {
            // Check if the current number is odd (meaning it ends with a 1 in binary)
            if (n % 2 == 1) {
                
                // Check if it ends in '11' in binary (remainder of 3 when divided by 4)
                if (n % 4 == 3) {
                    // Adding 1 is better because it groups multiple 1s together
                    n += 1;
                } else {
                    // It ends in '01', so subtracting 1 is the fastest way to clear it
                    n -= 1;
                }
                
                // We performed one operation (either add or subtract)
                operations++;
            }
            
            // Divide by 2 to shift the number and check the next position 
            n /= 2;
        }
        
        return operations;
    }
};