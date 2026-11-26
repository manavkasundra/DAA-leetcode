class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 1. Sort balloons normally (from left to right by their starting point)
        sort(points.begin(), points.end());
        int arrows = 1;
        int arrowEnd = points[0][1]; // The furthest right our current arrow can shoot
        // 2. Go through each remaining balloon
        for (int i = 1; i < points.size(); i++) {
            int start = points[i][0];
            int end = points[i][1];
            if (start > arrowEnd) {
                // This balloon is too far right, so we need a new arrow
                arrows++;
                arrowEnd = end;
            } else {
                // They overlap! Keep the smaller end so one arrow hits both
                arrowEnd = min(arrowEnd, end);
            }
        }
        return arrows;
    }
};