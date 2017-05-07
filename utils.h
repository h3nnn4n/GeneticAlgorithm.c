#ifndef UTILS_H
#define UTILS_H

#include "types.h"

_ga_data* ga_new();
void ga_set_bounds( _ga_data *ga, double lb, double ub );
void ga_set_encoding( _ga_data *ga, _ga_encoding enc );
void ga_set_pop_size( _ga_data *ga, int pop_size, int n_gens);
void ga_init_pop( _ga_data *ga );
void ga_init_values( _ga_data *ga );

#endif /* UTILS_H */
