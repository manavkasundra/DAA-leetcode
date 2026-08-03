class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a = 0, count = 0;
        for (int x : nums) 
        {
            if (count == 0)
            a = x;
            if (x == a) 
            count++;
            else count--;
        }
        return a;
    }
};