class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxL = 0, maxR = 0;
        maxL = max(maxL, height[l]);
        maxR = max(maxR, height[r]);
        int res = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                maxL = max(maxL, height[l++]);
                int tmp = maxL - height[l];
                res += tmp <= 0 ? 0: tmp;
            } else {
                maxR = max(maxR, height[r--]);
                int tmp = maxR - height[r];
                res += tmp <= 0 ? 0: tmp;
            }
        }

        return res;
    }
};
