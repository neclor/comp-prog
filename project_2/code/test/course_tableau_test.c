/**
 *
 *
*/

#include "seatest.h"

#include "course.h"

/* ======= Constants ======= */

const char *name1 = "Liege";

/* ======= Functions ======= */

static void test_course_total_time(void) {

}

static void test_course_append(void) {

}

static void test_fixture(void) {
   test_fixture_start();
   run_test(test_course_total_time);

   test_fixture_end();
}

static void all_tests(void) {
   test_fixture();
}

int main() {
   return run_tests(all_tests);
}
