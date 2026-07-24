class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (!isalnum(s[l]) and l < r) l++;
            while (!isalnum(s[r]) and l < r) r--;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
