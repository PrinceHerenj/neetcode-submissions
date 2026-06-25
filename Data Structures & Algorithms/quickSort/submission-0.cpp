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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortHelper(vector<Pair>& pairs, int l, int r) {
        if (r - l + 1 <= 1) return;

        Pair pivot = pairs[r];
        int left = l;


        for (int i = l; i < r; i++) {
            if (pairs[i].key < pivot.key) {
                swap(pairs[left], pairs[i]);
                left++;
            }
        }

        swap(pairs[left], pairs[r]);

        quickSortHelper(pairs, l, left - 1);
        quickSortHelper(pairs, left + 1, r);
    }
};
