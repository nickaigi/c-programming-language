#include<stdio.h>
#define MAXLINE 1000
#define SPACEFORTABS 4

int main(){
    int c, i;
    char line[MAXLINE];
    i = 0;

    while ((c = getchar()) != EOF && (i < MAXLINE - 2)){
        if (c == '\t'){
            for (int x = 0; x < SPACEFORTABS; x++, i++)
                line[i] = ' '; // for each \tab, remove the tab, and add 4 spaces
        }else {
            line[i] = c;
            i++;
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return 0;
}
