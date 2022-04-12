#include <gmp.h>

//Computes the modular inverse using a variation of bezout from GCD
//a^-1 mod n. Returns error if inverse does not exist.
extern long modInv_ll(long a, long n);

//Computes a^b mod n without overflow.
extern long powerMod_ll(long a, long b, long n);
//Sets a to a^b mod n
//Exponent must be positive. 
extern void powerMod_zz(mpz_t a, mpz_t b, mpz_t n);
