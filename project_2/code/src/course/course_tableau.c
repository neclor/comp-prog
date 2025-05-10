/**
 *
 *
*/

#include <assert.h>
#include <stdlib.h>

#include "bool.h"
#include "escale.h"

#include "course.h"

/* ======= Constants ======= */

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2

/* ======= Structures ======= */

struct Course {
   size_t escales_count;
   size_t escales_size;
   Escale **escales;
};

/* ======= Private Function Prototypes ======= */



/* ======= Public Functions ======= */

Course *course_create(const Escale *e1, const Escale *e2) {
   assert(e1 != NULL && e2 != NULL);



}

bool course_is_circuit(const Course *course);

size_t course_get_escales_count(const Course *course);

size_t course_get_stages_count(const Course *course);

double course_total_time(const Course *course);

double course_best_time_at(const Course *course, size_t index);

Course *course_append(Course *course, const Escale *escale);

Course *course_pop(Course *course);


/* ======= Private Functions ======= */
