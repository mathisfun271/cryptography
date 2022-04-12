#include <gmp.h>
// Simple Miller-Rabin on n with potential witness a.
// Returns 0 if composite, non-zero if PRP.
extern int millerRabin_l(long n, long w);

// Miller Rabin on arbitrary size integer.
extern int millerRabin_z(mpz_t n, long w);

//determines if an integer is a PRP.
//0 if composite, non-zero if PRP.
extern int mr_PRP_z(mpz_t n, int testCount);

// replaces n with next PRP after n.
extern void next_PRP(mpz_t n);
