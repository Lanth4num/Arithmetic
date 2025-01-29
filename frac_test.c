#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include <stdio.h>
#include "frac.h"

static void test_gcd(){
	CU_ASSERT( gcd(0, 0) == 0 );
	CU_ASSERT( gcd(5, 5) == 5 );
	CU_ASSERT( gcd(3, 6) == 3 );
	CU_ASSERT( gcd(6, 3) == 3 );
	CU_ASSERT( gcd(-3, 6) == 3 );
	CU_ASSERT( gcd(7, 13) == 1);
	CU_ASSERT( gcd(5784, 62) == 2);
	CU_ASSERT( gcd(806, 39) == 13);
}

static void test_gcd_ext(){
	int arr[3];

	gcd_ext(arr, 21, 6);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	gcd_ext(arr, 93, 77);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	gcd_ext(arr, 36, 30);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

}

static void test_frac_new(){
	Frac test = frac_new(3, 1);
	CU_ASSERT( test.numerator == 3 );
	CU_ASSERT( test.denominator == 1 );

	test = frac_new(3, 0);
	CU_ASSERT( test.numerator == 3 );
	CU_ASSERT( test.denominator == 1 );

	test = frac_new(-3, 0);
	CU_ASSERT( test.numerator == -3 );
	CU_ASSERT( test.denominator == 1 );

	test = frac_new(-7, -4);
	CU_ASSERT( test.numerator == -7 );
	CU_ASSERT( test.denominator == -4 );
}


static void test_frac_simplify(){
	Frac frac = frac_new(4, 8);
	frac_simplify(&frac);
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 2);

	frac = frac_new(-4, -10);
	frac_simplify(&frac);
	CU_ASSERT(frac.numerator == 2);
	CU_ASSERT(frac.denominator == 5);

	frac = frac_new(1, -2);
	frac_simplify(&frac);
	CU_ASSERT(frac.numerator == -1);
	CU_ASSERT(frac.denominator == 2);

	frac = frac_new(1, 0);
	frac_simplify(&frac);
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 1);
}


static void test_frac_mul_int(){
	Frac frac = frac_new(1, 4);
	frac = frac_mul_int(frac, 4);
	CU_ASSERT( frac.numerator == 1 );
	CU_ASSERT( frac.denominator == 1 );

	frac = frac_mul_int(frac_new(-1, 2), -3);
	CU_ASSERT( frac.numerator == 3 );
	CU_ASSERT( frac.denominator == 2 );

	frac = frac_mul_int(frac_new(10, 2), 0);
	CU_ASSERT( frac.numerator == 0 );
	CU_ASSERT( frac.denominator == 1 );
}


static void test_frac_mul(){
	Frac frac;

	frac = frac_mul(frac_new(2, 1), frac_new(1, 4));
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 2);

	frac = frac_mul(frac_new(-3, 5), frac_new(2, 3));
	CU_ASSERT(frac.numerator == -2);
	CU_ASSERT(frac.denominator == 5);

	frac = frac_mul(frac_new(-1, 5), frac_new(-1, 3));
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 15);
}


static void test_frac_add(){
	Frac frac;

	frac = frac_add(frac_new(1, 3), frac_new(2, 3));
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 1);

	frac = frac_add(frac_new(1, 3), frac_new(2, 5));
	CU_ASSERT(frac.numerator == 11);
	CU_ASSERT(frac.denominator == 15);

	frac = frac_add(frac_new(-1, 4), frac_new(1, 2));
	CU_ASSERT(frac.numerator == 1);
	CU_ASSERT(frac.denominator == 4);
}

int main(){
	/* Init */
	CU_initialize_registry();

	/* Creating suites */
	CU_pSuite arithSuite = CU_add_suite("ArithmeticSuite", NULL, NULL);
	CU_pSuite fracSuite = CU_add_suite("FracSuite", NULL, NULL);

	/* Adding test to arithmetic suite */
	CU_add_test(arithSuite, "test_gcd", test_gcd);
	CU_add_test(arithSuite, "test_gcd_ext", test_gcd_ext);
	
	/* Adding test to frac suite */
	CU_add_test(fracSuite, "test_frac_new", test_frac_new);
	CU_add_test(fracSuite, "test_frac_simplify", test_frac_simplify);
	CU_add_test(fracSuite, "test_frac_mul_int", test_frac_mul_int);
	CU_add_test(fracSuite, "test_frac_mul", test_frac_mul);
	CU_add_test(fracSuite, "test_frac_add", test_frac_add);

	/* Running all tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	return 0;
}





