#ifndef TYPES_H
#define TYPES_H

typedef enum {UNK_SE, ROULETTE, TOURNEY, RANDOM} _ga_selection;
typedef enum {UNK_CX, ONE_POINT, UNIFORM} _ga_crossover;
typedef enum {UNK_MU, TWO_SWAP} _ga_mutation;
typedef enum {UNK_EN, REAL, INT, PERMUT, BOOL} _ga_encoding;

typedef struct {
    int **pop_int;
    float **pop_real;
} _population;

typedef struct {
    float mutation_chance;
    float crossover_chance;
    float ub;
    float lb;
    int k_tourney;
    int k_elitism;

    int pop_size;
    int n_gens;

    _population population;

    _ga_selection selection;
    _ga_crossover crossover;
    _ga_mutation mutation;
    _ga_encoding encoding;
} _ga_data;

#endif /* TYPES_H */
