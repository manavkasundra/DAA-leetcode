class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int mid = (n - 1) / 2;
        int small = mid;
        int large = n - 1;
        
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                result[i] = sorted[small];
                small--;
            } else {
                result[i] = sorted[large];
                large--;
            }
        }
        
        nums = result;
    }
};