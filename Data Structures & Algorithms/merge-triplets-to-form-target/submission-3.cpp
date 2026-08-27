class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3, false);
        for (auto t: triplets) {
            if (t == target) return true;
            if (t[0] > target[0] or t[1] > target[1] or t[2] > target[2]) continue;
            if (!found[0] and t[0] == target[0]) found[0] = true;
            if (!found[1] and t[1] == target[1]) found[1] = true;
            if (!found[2] and t[2] == target[2]) found[2] = true;
            if (found[0] and found[1] and found[2]) return true;
        }

        return false;
    }
};
