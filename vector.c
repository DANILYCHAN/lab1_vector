#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

vector *init(int size, EL *type) {
    vector *vec = calloc(1, sizeof(vector));
    vec->size = size;
    vec->type = type;
    vec->data = calloc(size, type->size);
    return vec;
}

void *get(vector *a, int i) {
    return (char *)a->data+i*a->type->size;
}

void *isum(void *a, void *b) {
    int *sum = (int *) malloc(sizeof(int));
    sum[0] = (*(int *) a)  + (*(int *) b);
    return sum;
}

void *fsum(void *a, void *b) {
    float *sum = (float *) malloc(sizeof(float));
    sum[0] = *(float *) a + *(float *) b;
    return sum;
}



vector *summ(vector *a, vector *b) {
    vector *sum = init(a->size, a->type);
    for (int i = 0; i < a->size; i++) {
        void *temp = a->type->sum(get(a, i), get(b, i));
        memcpy(get(sum, i), temp, a->type->size);
        free(temp);
    }
    return sum;
}

void *ino_mem_sum(void *a, void *b) {
    *(int *)a += (*(int *) b);
    return a;
}

void *fno_mem_sum(void *a, void *b) {
    *(float *)a += (*(float *) b);
    return a;
}

vector *el_sum(vector *a) {
    vector *elem_sum = init(1, a->type);
    for (int i = 0; i < a->size; i++) {
        elem_sum->data = a->type->no_mem_sum(elem_sum->data, get(a, i));
    }
    return elem_sum;
}

void *imulti(void *a, void *b) {
    int *multi = (int *) malloc(sizeof(int));
    multi[0] = *(int *) a  * *(int *) b;
    return multi;
}

void *fmulti(void *a, void *b) {
    float *multi = (float *) malloc(sizeof(float));
    multi[0] = *(float *) a * *(float *) b;
    return multi;
}

vector *multi(vector *a, vector *b) {
    vector *skal = init(a->size, a->type);
    for (int i = 0; i < a->size; i++) {
        void *temp = a->type->multi(get(a, i), get(b, i));
        memcpy(get(skal, i), temp, a->type->size);
        free(temp);
    }
    vector *skal_multi = el_sum(skal);
    free(skal);
    return skal_multi;
}

void *ikread() {
    int *res = (int *) malloc(sizeof(int));
    scanf("%d", res);
    return res;
}

void *fkread() {
    float *res = (float *) malloc(sizeof(float));
    scanf("%f", res);
    return res;
}

void read(vector *a) {
    for (int i = 0; i < a->size; i++) {
        void *temp = a->type->kread();
        memcpy(get(a, i), temp, a->type->size);
        free(temp);
    }
}

void iout(void *a, int i) {
    printf("%d ", *((int *) a + i));
}

void fout(void *a, int i) {
    printf("%.2f ", *((float *) a + i));
}

vector out(vector *a) {
    for (int i = 0; i < a->size; i++) {
        a->type->out(a->data, i);
    }
}