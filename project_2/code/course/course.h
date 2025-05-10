/**
 *
 *
*/

#ifndef COURSE_H
#define COURSE_H

#include <stdlib.h>

#include "escale.h"

/* ======= Bool ======= */

#ifndef __bool_true_false_are_defined

#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#endif // __bool_true_false_are_defined

/* ======= Structures ======= */

typedef struct Course Course;

/* ======= Public Function Prototypes ======= */

Course *course_create(const Escale *e1, const Escale *e2);

bool course_is_circuit(const Course *course);

size_t course_get_escales_count(const Course *course);

size_t course_get_stages_count(const Course *course);

double course_total_time(const Course *course);

//TODO éterminer le meilleur temps d’une escale de la course certains ou n'importe lequel???
double course_best_time_at(const Course *course, size_t index);

//TODO: Je ne sais pas si c'est nécessaire, mais si tu veux tu peux ajouter un ajout par index
Course *course_append(Course *course, const Escale *escale);

Course *course_pop(Course *course);

#endif // COURSE_H
