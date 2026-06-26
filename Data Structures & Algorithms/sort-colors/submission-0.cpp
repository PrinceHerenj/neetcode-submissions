class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (auto x: nums) {
            mp[x]++;
        }

        int i = 0;
        for (int n = 0; n < mp.size(); n++) {
            while (mp[n]-- > 0) nums[i++] = n;
        }
    }
};