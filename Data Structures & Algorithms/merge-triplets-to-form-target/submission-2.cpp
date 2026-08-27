class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> temp = {1,1,1};
        for (auto t: triplets) {
            if (t == target) return true;
            if (t[0] <= target[0] and t[1] <= target[1] and t[2] <= target[2]) {
                temp = {max(temp[0], t[0]),
                        max(temp[1], t[1]),
                        max(temp[2], t[2])};
            }
        }

        if (temp == target) return true;
        return false;
    }
};
