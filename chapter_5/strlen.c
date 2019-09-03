#include <stdio.h>

int mystrlen(char *);

int main() {
    printf("mystrlen(\"hello, world\") = %d\n", mystrlen("hello, world"));
    /* Warning:
     * ISO C++11 does not allow conversion from string literal to 'char *' 
     */
    return 0;
}

/* strlen: return length of string s
 * name changed to mystrlen so as not to conflict with standard  lib strlen
 */
int mystrlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
