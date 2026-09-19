class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if (n == 1) return {0};

        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> st; // temp, index
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() and temperatures[i] > st.top().first) {
                auto [stTemp, stIndex] = st.top(); st.pop();
                res[stIndex] = (i - stIndex);
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};
