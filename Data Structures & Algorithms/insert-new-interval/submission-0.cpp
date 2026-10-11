class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int s = intervals.size();
        int i = 0;
        while (i < s and intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        while (i < s and intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        res.push_back(newInterval);


        while (i < s) {
            res.push_back(intervals[i++]);
        }

        return res;


    }
};
