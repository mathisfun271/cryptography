
#include "GCD.h"
#include <gmp.h>

long gcd_ll(long a, long b){
  long temp = b;
  while(b != 0){
    b = a % b;
    a = temp;
    temp = b;
  }
  return a;
}

long gcd_zl(mpz_t a, long b){
  return gcd_ll(b,mpz_fdiv_ui(a,b));
}

long bezout_ll(long* x1, long* y1, long a, long b){
  long temp = b;
  *x1 = 1;
  *y1 = 0;
  long x2 = 0, y2 = 1, q;
  while(b != 0){
    q = a / b;

    temp = x2;
    x2  = *x1 - q*x2;
    *x1 = temp;

    temp = y2;
    y2  = *y1 - q*y2;
    *y1 = temp;

    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
