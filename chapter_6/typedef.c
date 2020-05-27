/* c provides 'typedef' for creating new data type names. E.g.
 *      typedef int Length;
 *
 * makes the name 'Length' a synonym for 'int'. 'Length' can be used in
 * declarations, casts, etc in exactly the same ways that the 'int' type can
 * be:
 *      Length len, maxlen;
 *      Length *lengths[];
 *
 * Similarly, the declaration:
 *      typedef char *String;
 *
 * makes 'String' a synonym for 'char *' or character pointer, which can then
 * be used in declarations and casts:
 *      String p;
 *      int strcmp(String, String);
 *      p = (String) malloc(100);
 *
 * A more complicated example:
 */

#include<stdlib.h>
typedef struct tnode *Treeptr;

typedef struct tnode {  /* the tree node */
    char *word;            /* points to the next */
    int count;             /* number of occurrences */
    struct tnode *left;    /* left child */
    struct tnode *right;   /* right child */
} Treenode;


/* this creates two new type keywords called 'Treenode' (a structure) and
 * 'Treeptr' (a pointer to the structure). Then the routine 'talloc' could
 * become
 */

Treeptr talloc(void){
    return (Treeptr) malloc(sizeof(Treenode));
}

/* 'typedef' declaration does not create a new type, it merely adds a new name
 * for some existing type.
 * In effect, 'typedef' is like '#define', except that since it is interpreted
 * by the compiler, it can cope with textual substitutions that are beyond the
 * capabilities of the preprocessor.
 */

typedef int (*PFI)(char *, char *);

/* creates the type 'PFI' for
 * "pointer to function(of two char * arguments) returning 'int'"
 * which can be used in contexts like:
 */

PFI mystrcmp, mynumcmp;

/* beside asthetics, there are 2 main reasons for using 'typedefs'
 * 1. To parameterize a program against portability problems.
 *    - If 'typedefs' are used for data types that may be machine-dependent,
 *      only the 'typedefs' need change when the program is moved
 *      Common usage: using typedef names for various integer quantities, then
 *      make an appropriate set of choices of 'short', 'int', and 'long' for
 *      each host machine.
 *      Types like 'size_t' and ptrdiff_t' from the standard library are
 *      examples.
 *
 *  2. To provide better documentation for a program 
 *     -a type called a 'Treeptr' may be easier to understand than one declared
 *      only as a pointer to a complicated structure
 */
