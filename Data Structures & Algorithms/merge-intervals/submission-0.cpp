class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = res.back()[1];

            int start = intervals[i][0], end = intervals[i][1];

            if (start <= lastEnd) {
                res.back()[1] = max(end, lastEnd);
            } else {
                res.push_back({start, end});
            }
        }

        return res;
    }
};
