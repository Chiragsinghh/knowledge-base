class Solution {
private:
    long long MOD = 1e9 + 7;

    // Fast power algorithm: computes (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_indices = (n + 1) / 2;
        long long odd_indices = n / 2;

        long long even_combinations = power(5, even_indices);
        long long odd_combinations = power(4, odd_indices);

        return (even_combinations * odd_combinations) % MOD;
    }
};
