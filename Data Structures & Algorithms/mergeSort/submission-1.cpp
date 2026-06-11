// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void mergeSortHelper(vector<Pair>& pairs, int lp, int rp) {
        if (rp - lp + 1 <= 1) return;

        int mid = (lp + rp) / 2;

        mergeSortHelper(pairs, lp, mid);
        mergeSortHelper(pairs, mid + 1, rp);

        merge(pairs, lp, mid, rp);
    }

    void merge(vector<Pair>& pairs, int lp, int mid, int rp) {
        vector<Pair> L(pairs.begin() + lp, pairs.begin() + mid + 1);
        vector<Pair> R(pairs.begin() + mid + 1, pairs.begin() + rp + 1);

        int i = 0;
        int j = 0;
        int k = lp;

        while (i < L.size() && j < R.size()) {
            if (L[i].key <= R[j].key) {
                pairs[k++] = L[i++];
            } else {
                pairs[k++] = R[j++];
            }
        }

        while (i < L.size()) {
            pairs[k++] = L[i++];
        }

        while (j < R.size()) {
            pairs[k++] = R[j++];
        }
    }
};
