class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int temp = x;
        int rev = 0;
        while (x) {
            int d = x % 10;
            rev = rev * 10 + d;
            x /= 10;
        }

        if (temp == rev) return true;
        return false;
    }
};