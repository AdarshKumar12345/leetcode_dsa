class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            bool covered = false;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (intervals[j][0] <= intervals[i][0] &&
                    intervals[i][1] <= intervals[j][1]) {
                    covered = true;
                    break;
                }
            }

            if (covered) ans--;
        }

        return ans;
    }
};