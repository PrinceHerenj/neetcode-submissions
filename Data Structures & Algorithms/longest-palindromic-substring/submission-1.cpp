class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            int lp = i, rp = i;

            while (lp >= 0 and rp < s.size() and s[lp] == s[rp]) {
                if (rp - lp + 1 > res.size()) {
                    res = s.substr(lp, rp - lp + 1);
                }
                lp--;
                rp++;
            }

            lp = i, rp = i + 1;

            while (lp >= 0 and rp < s.size() and s[lp] == s[rp]) {
                if (rp - lp + 1 > res.size()) {
                    res = s.substr(lp, rp - lp + 1);
                }
                lp--;
                rp++;
            }
        }

        return res;
    }
};
