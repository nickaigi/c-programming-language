/* Complicated declarations:
 * - What is the difference between the following
 *      int *f();     // f: function returning pointer to int
 *
 *   and 
 *      int (*pf)();  // pf: pointer to function return int
 *
 * - point here is to write code that converts from valid C to a word
 *   description and back again. The word description reads left to right
 * - 'dcl' is more complex. Converts C declaration into a word description as
 *   in these examples:
 *
 *   char **argv
 *      argv: pointer to char
 *   int (*daytab)[13]
 *      daytab: pointer to array[13] of int
 *   void *comp()
 *      comp: function returning pointer to void
 *   void (*comp)()
 *      comp: pointer to functin returning void
 *   char (*(*x())[])()
 *      x: function returning pointer to array[] of pointer to function
 *      returning char
 *   char (*(*x[3])())[5]
 *      x: array[3] of pointer to function returning pointer to array[5] of
 *      char
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS };

void dcl(void);
void mydirdcl(void);
int gettoken(void);
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1000];

int main() {                /* convert declaration to words */
    while (gettoken() != EOF) {    /* 1st token on line */
        strcpy(datatype, token);   /* is the datatype */
        out[0] = '\0';
        dcl();                     /* parse rest of line */
        if (tokentype != '\n')
            printf("syntax erorr\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void) {   /* return next token */
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}


/* dcl: parse a declarator */
void dcl(void){
    int ns;

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;
    mydirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void mydirdcl(void){
    int type;
    if (tokentype == '('){  /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing ) \n");
    } else if (tokentype == NAME)  /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

/* dcl is illustrative, can only handle a simple data type  line char or int
 * can not handle argument types in functions or qualifiers like const... etc
 */
