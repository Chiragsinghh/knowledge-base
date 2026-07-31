class Solution {
public:
    double fastpow(double x, int n){
        if(n==0) return 1.0;
        if(n==1) return x;
        double halfpow = myPow(x,n/2);

        if(n%2!=0){
            return halfpow * halfpow * x;
        }else{
            return halfpow*halfpow;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x= 1/x;
            N=-N;
        }

        double result = 1.0;
        double current_product = x;
        
        // Iterative Binary Exponentiation
        while (N > 0) {
            // If the current bit is set, multiply the result
            if (N % 2 == 1) {
                result *= current_product;
            }
            // Square the base for the next bit position
            current_product *= current_product;
            // Shift down by halving N
            N /= 2;
        }
        
        return result;
        
    }
};