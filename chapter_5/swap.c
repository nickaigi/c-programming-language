/* Remember: C passes by value */
#include <stdio.h>

void swapbyvalue(int, int);
void swap(int *, int *);

int main() {
    int a = 4, b = 5;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swapbyvalue(a,  b);
    printf("After swap by value: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap by pointers: a = %d, b = %d\n", a, b);
    return 0;
}

void swapbyvalue(int x, int y){
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
