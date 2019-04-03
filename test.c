#include<stdio.h>

int main(){
    int i;
    int arr[10];
    int n1, n2;
    int x1, x2;

    n1 = n2 = 5;

    for (i = 0; i < 10; arr[i] = 1, ++i)
        ;

    ++arr[0];
    for (i = 0; i < 10; ++i)
        printf("%d\n", arr[i]);

    /*
     * Demonstrates pre-increment and post-increment
     * x = n++ means asign x to the value of n, then increment n by 1
     *
     * x = ++n means increment the value of n by 1, then asign that to x
     */
    x1 = n1++;
    x2 = ++n2;
    printf("x1 should be 5 and is: %d\n", x1);
    printf("x2 should be 6 and is: %d\n", x2);
    return 0;
}
