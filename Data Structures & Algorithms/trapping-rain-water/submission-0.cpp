class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size()), maxRight(height.size());
        int maxEl = 0;
        for (int i = 0; i < height.size(); i++) {
            maxLeft[i] = maxEl;
            maxEl = max(maxEl, height[i]);
        }
        maxEl = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxRight[i] = maxEl;
            maxEl = max(maxEl, height[i]);
        }

        vector<int> trappedWater(height.size());
        for (int i = 0; i < height.size(); i++) {
            int temp = min(maxLeft[i], maxRight[i]) - height[i];
            trappedWater[i] = temp > 0 ? temp : 0 ;
        }

        return accumulate(trappedWater.begin(), trappedWater.end(), 0);
        
    }
};
