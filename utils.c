#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "types.h"

_ga_data* ga_new() {
    _ga_data* ga = (_ga_data*) malloc ( sizeof(_ga_data) );

    ga->selection = UNK_SE;
    ga->crossover = UNK_CX;
    ga->mutation  = UNK_MU;
    ga->encoding  = UNK_EN;

    return ga;
}

void ga_set_encoding( _ga_data *ga, _ga_encoding enc ) {
    ga->encoding = enc;

    if ( enc == BOOL ) {
        ga->lb = 0;
        ga->ub = 0;
    }
}

void ga_set_bounds( _ga_data *ga, double lb, double ub ) {
    ga->lb = lb;
    ga->ub = ub;
}

void ga_set_pop_size( _ga_data *ga, int pop_size, int n_gens) {
    ga->pop_size = pop_size;
    ga->n_gens = n_gens;
}

void ga_init_pop( _ga_data *ga ) {
    if ( ga->encoding == REAL ) {
        ga->population.pop_real = (float**) malloc ( sizeof(float*) * ga->pop_size );
        for (int i = 0; i < ga->pop_size; ++i) {
            ga->population.pop_real[i] = (float*) malloc ( sizeof(float) * ga->n_gens );
        }
    } else {
        ga->population.pop_int = (int**) malloc ( sizeof(int*) * ga->pop_size );
        for (int i = 0; i < ga->pop_size; ++i) {
            ga->population.pop_int[i] = (int*) malloc ( sizeof(int) * ga->n_gens );
        }
    }
}

void ga_init_values( _ga_data *ga ) {
    if ( ga->encoding == REAL ) {
        for (int i = 0; i < ga->pop_size; ++i) {
            for (int j = 0; j < ga->n_gens; ++j) {
                float value = drand48();

                value *= ga->ub - ga->lb;
                value += ga->lb;

                ga->population.pop_real[i][j] = value;
            }
        }
    } else if ( ga->encoding == INT ) {

    } else if ( ga->encoding == BOOL ) {

    } else if ( ga->encoding == PERMUT ) {

    }
}
