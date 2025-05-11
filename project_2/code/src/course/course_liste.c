/**
 *
 *
*/

#include <assert.h>
#include <stdlib.h>

#include "bool.h"
#include "escale.h"

#include "course.h"

/* ======= Structures ======= */

struct Course {
   Escale *escale;
   Course *next;
};

/* ======= Private Function Prototypes ======= */

static Course *course_last(const Course *course);

/* ======= Public Functions ======= */

Course *course_create(Escale *e1, Escale *e2) {
   assert(
      e1 != NULL &&
      e2 != NULL &&
      escale_get_best_time(e1) == 0 &&
      escale_equal(e1, e2)
   );

   Course *course = malloc(sizeof(Course));
   if (course == NULL) {
      return NULL;
   }

   course->escale = e1;
   course->next = NULL;

   course_append(course, e2);

   return course;
}

bool course_is_circuit(const Course *course) {
   assert(course != NULL);

   if (course->next == NULL)
      return false;

   return escale_equal(
      course->escale,
      course_last(course)->escale
   );
}

size_t course_get_escales_count(const Course *course) {
   assert(course != NULL);

   if (course->next == NULL)
      return 1;

   return course_get_escales_count(course->next) + 1;
}

size_t course_get_stages_count(const Course *course) {
   assert(course != NULL);

   if (course->next == NULL)
      return 0;

   return course_get_stages_count(course->next) + 1;
}

double course_total_time(const Course *course) {
   assert(course != NULL);

   if (course->next == NULL)
      return escale_get_best_time(course->escale);

   return (
      course_total_time(course->next) + escale_get_best_time(course->escale)
   );
}

double course_best_time_at(const Course *course, size_t index) {
   assert(course != NULL && index < course_get_escales_count(course));

   if (index == 0)
      return escale_get_best_time(course->escale);

   return course_best_time_at(course->next, index - 1);
}

Course *course_append(Course *course, const Escale *escale) {
   assert(course != NULL && escale != NULL);

   if (course->next == NULL) {
      Course *new_course = malloc(sizeof(Course));
      new_course->escale = escale;
      new_course->next = NULL;
      course->next = new_course;
   } else {
      course_append(course->next, escale);
   }

   return course;
}

Course *course_pop(Course *course) {
   assert(course != NULL);

   if (course->next == NULL) {
      free(course->escale);
      free(course);
      return NULL;
   }

   course->next = course_pop(course->next);

   return course;
}

void course_free(Course *course) {
   if (course == NULL)
      return;

   course_free(course->next);
   free(course->escale);
   free(course);
}

/* ======= Private Functions ======= */

static Course *course_last(const Course *course) {
   assert(course != NULL);

   if (course->next == NULL)
      return course;

   return course_last(course->next);
}
