/* this code is typical of what might be found in the symbol table
 * management routines of a macro processor or a compiler
 *
 * for example, consider the
 *
 *      #define IN 1
 * is encountered, the name IN and the replacement text 1 are stored in a table
 * Later, when the name IN appears in a statement like
 *      state = IN;
 *
 * it must be replaced by 1.
 */

struct nlist {           /* table entry: */
    struct nlist *next;  /* next entry in chain */
    char *name;          /* defined name */
    char *defn;          /* replacement text */
};


#define HASHSIZE 101

static struct nlist *hastb[HASHSIZE];  /* pointer table */

/* hash: from hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;
    /* unsinged arithmetic ensures that the hash value is non negative */

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}
