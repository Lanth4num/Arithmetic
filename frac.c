#include "frac.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* sets arr to : gcd, m, n */
bool gcd_ext(int arr[3], int a, int b){

	int mpp = 1;
	int mp = 0;
	int npp = 0;
	int np = 1;

	while (b != 0) {
		int r = a%b;
		int q = (a-r)/b;
		a = b;
		b = r;
		int m = mpp - q * mp;
		int n = npp - q * np;
		mpp = mp;
		mp = m;
		npp = np;
		np = n;
	}

	int* ret = arr == NULL ? (int*) malloc(sizeof(int)*3) : arr;

	if (a >= 0){
		ret[0] = a;
		ret[1] = mpp;
		ret[2] = npp;
	} else {
		ret[0] = -a;
		ret[1] = -mpp;
		ret[2] = -npp;
	}

	return true;
}

int gcd(int a, int b){
	int r;
	while (b!=0) {
		r = a%b;
		a=b;
		b=r;
	}
	return abs(a);
}

bool frac_simplify(Frac* frac){
	Frac result;
	int n = frac->numerator;
	int d = frac->denominator;
	if (n%d == 0){
		result.numerator = n/d;	
		result.denominator = 1;	
	} else {
		int g = gcd(n, d);
		if (d>0) {
			result.numerator = n/g;
			result.denominator = d/g;
		} else if (d<0){
			result.numerator = -n/g;
			result.denominator = -d/g;
		} else {
			return false; /* Case invalid gcd */
		}
	}

	*frac = result;
	return true;
}

Frac frac_new(int a, int b){
	if (b == 0) b = 1;
	return (Frac){.numerator=a, .denominator=b};
}

Frac frac_mul_int(Frac a, int b){
	Frac result;

	result.numerator = a.numerator * b;
	result.denominator = a.denominator;
	frac_simplify(&result);

	return result;
}

Frac frac_mul(Frac a, Frac b){
	Frac result;

	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	frac_simplify(&result);

	return result;
}

Frac frac_add(Frac a, Frac b){
	Frac result;

	result.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	result.denominator = a.denominator * b.denominator;
	frac_simplify(&result);

	return result;
}

void frac_print(Frac frac){
	printf("%d/%d", frac.numerator, frac.denominator);
}

