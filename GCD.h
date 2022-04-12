#include <gmp.h>

// Computes GCD(a,b) using the Euclidean Algorithm.
extern long gcd_ll(long a, long b);
extern long gcd_zl(mpz_t a, long b);

// Determines the minimal Bezout coefficients using the Extended EA.
// Saves coeffs to pointers x1,y1, returns GCD.
extern long bezout_ll(long* x1, long* y1, long a, long b);
