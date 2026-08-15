class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        a = a % 1337; 
        for (int digit : b) {
            
            int part1 = 1;
            for (int i = 0; i < 10; i++) {
                part1 = (part1 * result) % 1337;
            }
            
            int part2 = 1;
            for (int i = 0; i < digit; i++) {
                part2 = (part2 * a) % 1337;
            }
            
            result = (part1 * part2) % 1337;
        }
        
        return result;
    }
};