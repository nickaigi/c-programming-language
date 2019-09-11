#include <stdio.h>

int mystrlen(char *);
int improvedstrlen(char *);

int main() {
    printf("mystrlen(\"hello, world\") = %d\n", mystrlen("hello, world"));
    /* Warning:
     * ISO C++11 does not allow conversion from string literal to 'char *' 
     */
    printf("improvedstrlen(\"hello, world\") = %d\n", improvedstrlen("hello, world"));
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

/* Improved strlen
 * 
 * if the pointes p and q point to the members of the same array
 * and p < q then q - p + 1 is the number of elements from p to q inclusive
 */

int improvedstrlen(char *s) {
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}
