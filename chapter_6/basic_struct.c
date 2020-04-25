/* - keyword 'struct' introduces a structure declaration, which is a list of
 *   declarations enclosed in braces.
 * - An optional name called a 'structure tag' may follow the key word 'struct'
 *   (as 'point' here)
 * - the variables named in a structure are called 'members'
 */

#include<stdio.h>

struct point {
    int x;
    int y;
};

int main(){
    struct point pt = { 5, 10 };
    printf("pt(%d, %d)\n", pt.x, pt.y);
    return 0;
}
