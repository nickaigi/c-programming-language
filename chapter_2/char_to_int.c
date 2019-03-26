#include<stdio.h>

int convert(char a){
    // return numeric value of a digit
    return a -'0';
}
int main(){
    int i;
    char c[5] = {'1', '2', '3', '4', '5'};
    for(i = 0; i < 5; i++)
        printf("%d\n", convert(c[i]));
}
