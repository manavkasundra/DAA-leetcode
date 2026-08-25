class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1)
            return {1};

        vector<int> odd = beautifulArray((n + 1) / 2);
        vector<int> even = beautifulArray(n / 2);

        vector<int> ans;

        for (int i = 0; i < odd.size(); i++) {
            ans.push_back(2 * odd[i] - 1);
        }

        for (int i = 0; i < even.size(); i++) {
            ans.push_back(2 * even[i]);
        }

        return ans;
    }
};