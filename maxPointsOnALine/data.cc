#include "algorithm.h"

struct Point* createData(int x[], int y[], int size) {

    struct Point *point;
    point = (struct Point*) malloc(sizeof(struct Point) * size);
    int i = 0;

    for (i; i < size; i++) {
        (point + i)->x = x[i];
        (point + i)->y = y[i];
    }

    return point;
}

void print(struct Point *point, int size) {
    
    for (int i = 0; i < size; i++) {
        printf("x = %d, y = %d \n", (point+i)->x, (*(point+i)).y);
    }
}
