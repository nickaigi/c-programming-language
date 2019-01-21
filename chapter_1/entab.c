#include<stdio.h>
#define MAXLINE 1000
#define SPACEFORTABS 4

int main(){
    int c, i;
    int spacecount = 1; // setspacecount to 1, since we only meet spacecount if lastc was a ' '
    char line[MAXLINE];
    char lastc = 'a'; // abitrary value of lastchar 
    i = 0;

    while ((c = getchar()) != EOF && (i < MAXLINE - 2)){
        if (c == ' ' && lastc == ' '){
            ++spacecount;
            if (spacecount == SPACEFORTABS){
                // TODO we are losing the rest of the string if we execute this section
                line[i] = '\t';
                ++i;
                spacecount = 0;
            }else{
                for(int x = 1; x <= spacecount; ++x){
                    line[i + x] = ' ';
                    ++i;
                }
                spacecount = 0;
            }
        }else {
            line[i] = c;
            ++i;
        }
        lastc = c;
    }
    line[i] = '\0';
    printf("%s\n", line);
    return 0;
}
