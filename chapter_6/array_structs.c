/* consider writing a program to count the occurrences of each C keyword */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main(){
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                    keytab[n].count, keytab[n].word);
    return 0;
}
/* - since the structure keytab contains set of names, it is easiest to make it
 *   an external variable and initialize it once and for all when it is defined.
 * - The initializers are listed in pairs corresponding to the structure
 *   members. It would be more precise to enclose the initializers for each
 *   "row" or structure in braces like
 *
 *          {"auto", 0 },
 *          {"break", 0 },
 *          {"case", 0 },
 *
 *   but inner braces are not necessary when the initializers are simple
 *   variables or character strings and when all are present
 */
