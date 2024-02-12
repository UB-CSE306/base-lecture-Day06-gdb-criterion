#include <stdio.h>
#include <criterion/criterion.h>
#include "code.h"

// Helper functions

void run_factorial_test(int a, long unsigned expected) {
    long unsigned actual = factorial(a);
    cr_assert_eq( actual, expected, "factorial(%d) should have been %lu, but was %lu", a, expected, actual);
}
  
void run_convert_test(char * str, int expected) {
    int actual = convert(str);
    cr_assert_eq( actual, expected, "convert(%s) should have been %d, but was %d.", str, expected, actual);
}
  
// Tests

Test(suite_factorial, test_0) { run_factorial_test(0,1); }
Test(suite_factorial, test_1) { run_factorial_test(1,1); }
Test(suite_factorial, test_2) { run_factorial_test(2,2); }
Test(suite_factorial, test_3) { run_factorial_test(3,6); }


Test(suite_convert, test_0) { run_convert_test("0",0); }
Test(suite_convert, test_1) { run_convert_test("1",1); }
Test(suite_convert, test_2) { run_convert_test("2",2); }
Test(suite_convert, test_3) { run_convert_test("12",12); }
Test(suite_convert, test_4) { run_convert_test("21",21); }


