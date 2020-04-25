/* - keyword 'struct' introduces a structure declaration, which is a list of
 *   declarations enclosed in braces.
 * - An optional name called a 'structure tag' may follow the key word 'struct'
 *   (as 'point' here)
 * - the variables named in a structure are called 'members'
 */

#include<stdio.h>

#define XMAX 3200
#define YMAX 3200

struct point {
    int x;
    int y;
};

/* structures can be nested */
struct rect {
    struct point pt1;
    struct point pt2;
};

/* legal operations on a structure:
 *      - copying it
 *      - assigning to it as a unit
 *      - taking its address with '&'
 *      - accessing its members
 * structures may not be compared
 */

int main(){
    struct point pt = { 5, 10 };
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                        (screen.pt1.y + screen.pt2.y)/2);
    printf("pt(%d, %d)\n", pt.x, pt.y);

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
