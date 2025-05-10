/**
 *
 *
*/

#include <assert.h>
#include <stdlib.h>

#include "bool.h"

#include "escale.h"

/* ======= Structures ======= */

struct Escale {
   const char *name;
   double x;
   double y;
   double best_time;
};

/* ======= Private Function Prototypes ======= */



/* ======= Public Functions ======= */

Escale *escale_create(const char *name, double x, double y) {
   assert(name != NULL);

   Escale *escale = malloc(sizeof(Escale));
   if (escale == NULL)
      return NULL;

   escale->name = name;
   escale->x = x;
   escale->y = y;
   escale->best_time = 0;

   return escale;
}

const char *escale_get_name(const Escale *escale) {
   assert(escale != NULL);

   return escale->name;
}

double escale_get_x(const Escale *escale) {
   assert(escale != NULL);

   return escale->x;
}

double escale_get_y(const Escale *escale) {
   assert(escale != NULL);

   return escale->y;
}

double escale_get_best_time(const Escale *escale) {
   assert(escale != NULL);

   return escale->best_time;
}

void escale_set_best_time(Escale *escale, double best_time) {
   assert(escale != NULL);

   escale->best_time = best_time;
}

double escale_distance(const Escale *e1, const Escale *e2) {
   assert(e1 != NULL && e2 != NULL);

   return 0;
}

bool escale_equal(const Escale *e1, const Escale *e2) {
   assert(e1 != NULL && e2 != NULL);

   return e1->x == e2->x && e1->y == e2->y;
}

/* ======= Private Functions ======= */
