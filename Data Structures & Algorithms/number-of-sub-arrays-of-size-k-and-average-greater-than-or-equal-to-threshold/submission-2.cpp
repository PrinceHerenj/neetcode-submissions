class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> prefixSum(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            prefixSum[i + 1] = arr[i] + prefixSum[i];
        }

        for (auto x: prefixSum) cout << x << " ";

        int res = 0;
        for (int i = k; i < prefixSum.size(); i++) {
            int rangeSum = prefixSum[i] - prefixSum[i - k];
            if (rangeSum >= threshold * k) res++;
        }
        return res;
    }
};