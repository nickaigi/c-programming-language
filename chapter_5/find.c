#include <stdio.h>
#include <string.h>
#define MAXLINE 10000

int mygetline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[]){
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pettern\n");
    else
        while (mygetline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    return found;
}

/* mygetline: get line into s, return length */
int mygetline(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';
    return s -t;
}
