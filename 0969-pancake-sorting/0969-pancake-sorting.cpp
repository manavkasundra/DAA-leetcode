class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();

        for (int target = n; target > 1; target--) {
            int idx = 0;
            while (arr[idx] != target) {
                idx++;
            }

            if (idx == target - 1) {
                continue;
            }

            if (idx != 0) {
                result.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }

            result.push_back(target);
            reverse(arr.begin(), arr.begin() + target);
        }

        return result;
    }
};