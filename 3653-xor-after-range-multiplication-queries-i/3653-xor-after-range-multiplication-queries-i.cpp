class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        vector<long long> values(nums.begin(), nums.end());

        for (auto query : queries) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int value = query[3];

            int index = left;

            while (index <= right) {
                values[index] =
                    (values[index] * value) % MOD;

                index = index + step;
            }
        }

        int result = 0;

        for (long long value : values) {
            result = result ^ (int)value;
        }

        return result;
    }
};