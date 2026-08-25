class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        int r = 0;

        while (r < nums.size()) {
            while (!dq.empty() and nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if (dq.front() < r - k + 1) {
                dq.pop_front();
            }

            if ((r + 1) >= k) {
                res.push_back(nums[dq.front()]);
            }

            r++;
        }

        return res;
    }
};
