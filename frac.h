#ifndef INCLUDE_FRAC
#define INCLUDE_FRAC

#include <stdbool.h>

struct Frac{
	int denominator;
	int numerator;
};
typedef struct Frac Frac;

int gcd(int a, int b);
bool gcd_ext(int arr[3], int a, int b);

bool frac_simplify(Frac* frac);
Frac frac_new(int a, int b);
Frac frac_mul_int(Frac a, int b);
Frac frac_mul(Frac a, Frac b);
Frac frac_add(Frac a, Frac b);
void frac_print(Frac frac);

#endif  // INCLUDE_FRAC
