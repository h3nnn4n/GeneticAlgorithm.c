#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "types.h"

int main() {

    _ga_data *ga = ga_new();

    ga_set_encoding(ga, REAL);
    ga_set_bounds(ga, -2, 2);
    ga_set_pop_size(ga, 10, 10);
    ga_init_pop(ga);
    ga_init_values(ga);

    for (int i = 0; i < ga->pop_size; ++i) {
        for (int j = 0; j < ga->n_gens; ++j) {
            printf("%8.4f ", ga->population.pop_real[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
