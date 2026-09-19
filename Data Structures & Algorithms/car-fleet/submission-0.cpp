class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        vector<double> st;

        for (auto &[position, speed]: pair) {
            st.push_back((double)(target - position) / speed);
            if (st.size() >= 2 and st.back() <= st[st.size() - 2]) st.pop_back();
        }

        return st.size();
    }
};
