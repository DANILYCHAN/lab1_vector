#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
    int type = 0;
    int size = 0;
    int act = 0;
    vector *a = NULL;
    vector *b = NULL;
    vector *c = NULL;
    EL *mir = NULL;

    printf("What type of data: 0 - int, 1 - float\n");
    scanf("%d", &type);

    if (type == 0) {
        mir = &INT_Type;
    } else if (type == 1) {
        mir = &FLT_Type;
    }

    printf("What is the dimension of the vector\n");
    scanf("%d", &size);

    a = init(size, mir);
    b = init(size, mir);

    printf("Enter the values of 1st vector seperated by a space\n");
    read(a);
    printf("Enter the values of 2nd vector seperated by a space\n");
    read(b);

    printf("What would you like to do: 0 - Vector addition, 1 - Inner product\n");
    scanf("%d", &act);

    if (act == 0) {
        c = summ(a, b);
        out(c);
        free(c);
    } else if (act == 1) {
        c = multi(a, b);
        out(c);
        free(c);
    }

    free(a);
    free(b);

    return 0;
}