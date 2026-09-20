class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // index, height
        for (int i = 0; i < heights.size(); i++) {
            if (st.empty()) st.push({i, heights[i]});
            else {
                if (heights[i] >= st.top().second) st.push({i, heights[i]});
                else {
                    int indexReached;
                    while (!st.empty() and heights[i] < st.top().second) {
                        indexReached = st.top().first;
                        maxArea = max(maxArea, (i - indexReached) * st.top().second);
                        st.pop();
                    }
                    st.push({indexReached, heights[i]});
                }
            }
        }

        int i = heights.size();
        while (!st.empty()) {
            auto [index, height] = st.top(); st.pop();
            maxArea = max(maxArea, (i - index) * height);
        }

        return maxArea;
    }
};
