/* detab
 * the tab stops are at every TABINC position
 * therefore, the program pads the string
 * with spaces required to arrive at the tabstop
 */
#include<stdio.h>
#define TABINC 8

int main(){
    int c, nb, pos;
    nb = 0;
    pos = 1;

    while ((c = getchar()) != EOF){
        if (c == '\t'){
            /* introduces the modulus operator
             * a = n % y
             * a is the remainder when n is divided by y
             */
            nb = TABINC - (pos - 1) % TABINC;
            /* nb is the number of blanks necessary to reach the next tab stop*/
            while (nb > 0){
                putchar('x');
                ++pos;
                --nb;
            }
        } else if (c == '\n'){
            putchar(c);
            pos = 1;
        } else{
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
