#include<stdio.h>
#define MAX 1000

void rev(void);

char s[MAX];
char reveresed[MAX];
int len;

int main(){
    int c;
    extern int len;
    len = 0;
    while ((c = getchar()) != EOF){
        s[len] = c;
        len++;
    }
    rev();
    return 0;
}
void rev(void){
    extern char s[];
    extern char reveresed[];
    int rcount = 0;
    for(int i = len -1 ; i >= 0; i--){
        reveresed[rcount] = s[i];
        rcount++;
    }
    reveresed[rcount + 1] = '\0';
    printf("%s\n", reveresed);
}
