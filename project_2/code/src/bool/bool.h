/**
 *
 *
*/

#ifndef BOOL_H
#define BOOL_H

// Avoiding conflicts with stdbool.h
#ifndef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1

#define bool _Bool
#define true 1
#define false 0

#endif // __bool_true_false_are_defined

#endif // BOOL_H
