#include<stdio.h>
#include<stdlib.h> /* utility functions including number convertions that we need */
#include "myutils.h" /* demonstrates how to write a custom header file*/

int winningseat(int total);

int main(int argc, char *argv[]){
    /* argc - argument count
     * argv - argument vector
     * by convention, argv[0] is the name b which the program was invoked
     * so argc is at least 1
     * if argc is 1, there are no command-line args
     * */
    char* n;
    int total;
    if (argc == 1){
        printf("Please provide the total as a command line argument\n");
    } else{
        n = argv[1];
        total = atoi(n); /* converts n to int*/
        printf("total: %d\n", total);
        printf("winning seat: %d\n", winningseat(total));    
    }
    return 0;
}

int winningseat(int total){
    /* to solve the Josephus problem, we need
     * total = 2^a + l
     * winningseat(total) = 2 * l + 1
     *
     * we know that winningseat(total) = 1 if total = 1 or total = 2
     */
    int a, l;

    if (total < 1)
        return -1;
    if (total <= 2)
        return 1;
    for (a = 1; a < total; a++){
        if (power(2, a + 1) > total){
            l = total - power(2, a);
            return (2 * l + 1);
        }
    }
    return -1; // error
}
