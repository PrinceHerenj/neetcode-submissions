class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int l = 0, r = 0, res = 1;
        while (r < arr.size()) {
            if (arr[r] == arr[l]) r++;
            else {
                swap(arr[++l], arr[r++]);
                res++;
            }
        }
        return res;
    }
};