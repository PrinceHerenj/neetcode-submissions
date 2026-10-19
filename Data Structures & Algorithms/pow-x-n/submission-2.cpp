class Solution {
public:
    double helper(double x, long long n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        
        double res = helper(x * x, n / 2);
        return n % 2 ? x * res : res;
    }

    double myPow(double x, int n) {
        long long exp = n;
        double res = helper(x, abs(exp));
        return n >= 0 ? res : 1 / res;
    }
};