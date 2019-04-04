#include<stdio.h>
#define MAX 30

void squeeze(char[], int);
int main(){
    char s[MAX] = "evanescence";
    printf("Word:    %s\n", s);
    squeeze(s, 'e');
    printf("squeeze: %s\n", s);
    return 0;
}

/* squeeze removes all occurences of the character
 * c from the string s
 * */
void squeeze(char s[], int c){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
