class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int myCoins = 0;
        int n = piles.size();
        
        for (int i = n - 2; i >= n / 3; i -= 2) {
            myCoins += piles[i];
        }

        return myCoins;
    }
};