class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, curSum = 0;

        for (int i = 0; i < k - 1; i++) curSum += arr[i];
        cout << curSum << endl;

        for (int L = 0; L <= arr.size() - k; L++) {
            curSum += arr[L + k - 1];
            if (curSum >= threshold * k) res++;
            curSum -= arr[L];
        }
        
        return res;
    }
};