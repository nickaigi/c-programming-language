#include<stdio.h>

#define NONBLANK 'a'

int main(){
    int c, lastc;

    lastc = NONBLANK;
    /* we read the "text stream"
     *
     * when we encounter a new line
     * we drop into the loop
     *
     * getchar and putchar operate on per character basis
     * so we can inspect each character while in the loop
     *
     * c holds the integer representation of the character
     *
     * putchar prints the char representaiton of the int
     */
    while ((c = getchar()) != EOF){
       /* if c is not a blank, print it to the screen */
       if (c != ' ')
           putchar(c);

       /* if c is a blank
        * check if the last char we entered was also a blank
        * if lastchar was not a blank, print c */
       if (c == ' ')
           if (lastc != ' ')
               putchar(c);

       /* if lastchar was a blank, don't print current c
        * update lastc to hold current c*/
       lastc = c;
    }
    return 0;
}
