/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int prevEnd = 0;
        sort(intervals.begin(), intervals.end(), [&](const Interval a, const Interval b) {return a.start < b.start;});
        for (auto [start, end]: intervals) {
            if (start < prevEnd) return false;
            prevEnd = end;
        }

        return true;
    }
};
