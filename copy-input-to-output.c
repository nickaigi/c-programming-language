#include<stdio.h>

int main(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
    /* on Unix use Ctrl-D to invoke EOF */
    return 0;
}
