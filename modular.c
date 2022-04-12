
#include "modular.h"
#include <stdlib.h>
#include <stdio.h>

long modInv_ll(long a, long n){
  long b = n;
  long temp = b;
  long x1 = 1, x2 = 0;
  while(b != 0){
    temp = x2;
    x2 = x1 - (a/b) * x2;
    x1 = temp;

    temp = b;
    b = a % b;
    a = temp;
  }
  if(a != 1){
    printf("Error in modInv_ll: Inverse does not exist, gcd=%d",a);
    exit(1);
  }

  return ((x1<0) ? n : 0) + x1;
}

long powerMod_ll(long a, long b, long n){
  if(b<0){
    a = modInv_ll(a,n);
    b *= -1;
  }
  long out = 1;
  while(b!=0){
    if(b%2 > 0){
      out = (out * a) % n;
    }
    b /= 2;
    a = (a*a) % n;
  }

 return out;
}

void powerMod_zz(mpz_t a, mpz_t b, mpz_t n){
  mpz_t out;
  mpz_init_set_ui(out,1);
  long bitMax = mpz_sizeinbase(b,2)+2;
  for(int i=0;i<bitMax;i++){
    if(mpz_tstbit(b,i)){

      mpz_mul(out,out,a);
      mpz_mod(out,out,n);

    }
    mpz_mul(a,a,a);
    mpz_mod(a,a,n);
  }
  mpz_set(a,out);
}
