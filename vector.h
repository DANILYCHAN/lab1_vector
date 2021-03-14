#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

#include "stdint.h"

struct EL {
    void *(*sum)(void *, void *);           // Addition
    void *(*no_mem_sum)(void *, void *);    // Addition second to first
    void *(*multi)(void *, void *);         // Multiplication
    void *(*kread)();                       // Reading
    void (*out)(void *, int);               // Output
    uint8_t size;                           // Type size
};

typedef struct EL EL;

void *isum(void *a, void *b);           // summ for integers

void *fsum(void *a, void *b);           // summ for floats

void *ino_mem_sum(void *a, void *b);    // Addition second to first for integers

void *fno_mem_sum(void *a, void *b);    // Addition second to first for floats

void *imulti(void *a, void *b);         // multiply for integers

void *fmulti(void *a, void *b);         // multiply for floats

void *ikread();                         // reading from keyboard for integers

void *fkread();                         // reading from keyboard for floats

void iout(void *a, int i);           // output for integers

void fout(void *a, int i);           // output for floats

static EL INT_Type = {isum, ino_mem_sum, imulti, ikread,  iout, sizeof(int)};    // functions for integers
static EL FLT_Type = {fsum, fno_mem_sum, fmulti,  fkread,  fout, sizeof(float)}; // functions for floats

struct vector {
    int size;   // vector size
    void *data; // vector elements
    EL *type;   // pointer to vector actions
};

typedef struct vector vector;

vector *init(int size, EL *type);       // zero vector initialization

void *get(vector *a, int i);            // returns the i-th element of the vector

vector *summ(vector *a, vector *b);     // vector addition of two vectors

vector *multi(vector *a, vector *b);      // dot product of two vectors

void read(vector *a);                   // reading vector from keyboard

vector out(vector *a);                  // vector output

vector *el_sum(vector *a);                 // summ of vector elements

#endif //LAB1_VECTOR_H