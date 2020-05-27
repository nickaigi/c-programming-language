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

/* The hashing process produces a starting index in the array 'hashtab'
 * if the string is found anywhere, it will be in the list of blocks beginning there.
 * The search is performed by 'lookup'
 * If 'lookup' finds the entry already present, it returns a pointer to it,
 * if not, it returns NULL
 */

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np-next)
        if (strcmp(s, np->name) == 0 )
            return np;  /* found */
    return NULL;        /* not found */
