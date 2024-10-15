#include <stdio.h>

void swap(int *a, int *b);

int main(void) {

    int x = 6;
    int y = 4;
    printf("Unswapped: x - %i, y - %i --> ", x, y);
    swap(&x, &y);
    printf("Swapped: x - %i, y - %i\n", x, y);
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}