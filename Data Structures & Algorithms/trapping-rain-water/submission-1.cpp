class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        int res = 0;
        while (l < r) {
            maxLeft = max(maxLeft, height[l]); maxRight = max(maxRight, height[r]);
            int temp;
            if (maxLeft < maxRight) {
                temp = maxLeft - height[l++];
            } else {
                temp = maxRight - height[r--];
            }
            res += temp >= 0 ? temp : 0;
        }

        return res;
    }
};
