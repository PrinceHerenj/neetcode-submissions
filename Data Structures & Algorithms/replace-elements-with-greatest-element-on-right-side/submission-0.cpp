class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxEl = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            int temp = maxEl;
            if (arr[i] > maxEl) maxEl = arr[i];
            arr[i] = temp;
        }
        return arr;
    }
};