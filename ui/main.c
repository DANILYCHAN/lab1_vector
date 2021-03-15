#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

const char *MSGS[] = {"0. Quit", "1. Choose type of data", "2. Entering the dimension of vectors", "3. Entering vector elements", "4. Vector addition", "5. Dot product of vectors"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

int main() {
    int c = 0;
    int type = -1;
    int size = 0;
    vector *a = NULL;
    vector *b = NULL;
    vector *res = NULL;
    EL *mir = NULL;
    do {
        c = dialog(MSGS, MSGS_SIZE);
        switch(c) {
            case 0:
                break;
            case 1:
                printf("What type of data: 0 - int, 1 - float\n");
                scanf("%d", &type);
                if (type != 0 && type != 1) {
                    puts("You're wrong. Try again!");
                    type = -1;
                } else {
                    if (type == 0) {
                        mir = &INT_Type;
                    } else if (type == 1) {
                        mir = &FLT_Type;
                    }
                }
                break;
            case 2:
                if (type == -1) {
                    puts("You didn't choose type of data. Choose it first!");
                } else {
                    printf("What is the dimension of the vector\n");
                    scanf("%d", &size);
                    if (size <= 0) {
                        puts("Dimension can't be <= 0. Try again");
                        size = 0;
                    } else {
                        a = init(size, mir);
                        b = init(size, mir);
                    }
                }
                break;
            case 3:
                if (a != NULL) {
                    free(a);
                    free(b);
                    a = init(size, mir);
                    b = init(size, mir);
                }
                if (type == -1) {
                    puts("You didn't choose type of data. Choose it first!");
                } else if (size == 0) {
                    puts("You didn't choose dimension of vector. Choose it first!");
                } else {
                    printf("Enter the values of 1st vector seperated by a space\n");
                    read(a);
                    printf("Enter the values of 2nd vector seperated by a space\n");
                    read(b);
                }
                break;
            case 4:
                if (a == NULL) {
                    puts("You didn't entered vectors. Enter vector elemnts first!");
                } else {
                    res = summ(a, b);
                    out(res);
                    free(res);
                }
                break;
            case 5:
                if (a == NULL) {
                    puts("You didn't entered vectors. Enter vector elemnts first!");
                } else {
                    res = multi(a, b);
                    out(res);
                    free(res);
                }
                break;
        }
    } while (c != 0);

    if (a != NULL) {
        free(a);
        free(b);
    }

    return 0;
}