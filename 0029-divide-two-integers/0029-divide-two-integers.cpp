class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special case: overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
              }

              long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long result = 0;

        // Subtract divisor using powers of 2
        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Check whether answer should be negative
        if ((dividend < 0) != (divisor < 0)) {
            result = -result;
        }

        return result;
    }
};