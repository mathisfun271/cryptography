
#include "GCD.h"
#include "modular.h"
#include <stdio.h>

int millerRabin_l(long n, long a){
  if(n % 2 == 0 || gcd_ll(n,a) > 1){
    return 0;
  }

  long k = 0, q = n - 1;
  while(q%2 == 0){
    k++;
    q /= 2;
  }

  a = powerMod_ll(a,q,n);
  if(a == 1){
    return 1;
  }
  for(int i;i<k;i++){
    if(a == n - 1){
      return 1;
    }
    a = (a*a) % n;
  }
  return 0;
}

int millerRabin_z(mpz_t n, long a){
  if(mpz_even_p(n) || gcd_zl(n,a) > 1){
    return 0;
  }

  long k = 0;
  mpz_t q;
  mpz_init(q);
  mpz_sub_ui(q,n,1);
  while(mpz_even_p(q)){
    k++;
    mpz_divexact_ui(q,q,2);
  }
  mpz_t az;
  mpz_init_set_ui(az,a);
  powerMod_zz(az,q,n);

  if(!mpz_cmp_ui(az,1)){
    return 1;
  }

  mpz_sub_ui(q,n,1);
  for(long i=0;i<k;i++){
    if(!mpz_cmp(az,q)){
      return 1;
    }
    mpz_mul(az,az,az);
    mpz_mod(az,az,n);
  }

  return 0;
}

int mr_PRP_z(mpz_t n, int testCount){
  for(int i = 2;i<testCount+2;i++){
    if(!millerRabin_z(n,i)){
      printf("%i ",i);
      return 0;
    }
  }
  return 1;
}

void next_PRP(mpz_t n){
  while(!mr_PRP_z(n,50)){
    mpz_add_ui(n,n,1);
  }
}
