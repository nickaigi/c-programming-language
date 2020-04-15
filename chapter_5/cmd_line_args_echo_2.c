/*
 * since argv is a pointer to an array of pointers, we can manipulate the
 * pointer rather than index the array.
 * this version is based on incrementing argv, which is a pointer to pointer
 * to char, while argc is counted down
 */

#include <stdio.h>
/* echo command-line arguments; 2nd version */
main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " ": "");
    printf("\n");
    return 0;
}
