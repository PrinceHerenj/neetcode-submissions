class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            int s = 0;
            for (char is: to_string(n)) {
                int i = is - '0';
                s += i * i;
            }
            if (seen.contains(s)) return false;
            seen.insert(s);
            n = s;
        }

        return true;

    }
};
