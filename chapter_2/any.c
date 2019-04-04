#include<stdio.h>
#include<string.h>
#define MAX 30


int any(char[], char[]);

int main(){
    char s1[MAX] = "blinkenlight";
    char s2[MAX] = "knight";
    int pos;
    printf("s1:          %s\n", s1);
    printf("s2:          %s\n", s2);

    pos = any(s1, s2);
    printf("first occurence at pos: %d\n", pos);

    return 0;
}

/* return the first location in a string s1 where any character from the
 * string s2 occurs, or -1 if s1 contains no characters from s2
 * */

int any(char s1[], char s2[]){
    int i, j;
    for(i=0; s1[i] != '\0'; i++){
        for(j=0; s2[j] != '\0'; j++){
            printf("s1[%d]: %c s2[%d]: %c\n", i, s1[i], j, s2[j]);
            if(s1[i] == s2[j])
                return ++i; // i is zero indexed, so we increment i by 1. Note my use of the pre-increment
        }
    }
    return -1;
}
