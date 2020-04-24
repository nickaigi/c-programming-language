/* undcl: convert word descriptions to declarations */
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


int main() {
    int type;
    char temp[MAXTOKEN];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while((type = gettoken()) != '\n') {
            if (type = PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                sprintf(temp, "(*%s)", token, out);
                strcpy(out, temp);
            } else if(type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        }
    }
    return 0;
}
