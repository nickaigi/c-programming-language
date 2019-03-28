/* to compile, use -lm to link the math library to your binary
 * $ gcc htoi.c -o htoi -lm
 *
 * use convention method of writing hex numbers 0xNumber
 * */
#define HEX_BASE 16
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int htoi(char[]);
int position(char[],int, char);
int hex_symbol(char);

int main(){
    // TODO check that char part of the hex number
    // falls within a..f and A..F
    printf("Integer value of 0x%s is %d\n", "3f", htoi("3f"));
}

int htoi(char h[]){
    /*
     * to convert 3f hex to int
     * 3 * pow(16,1) + f * pow(16, 0)
     */
    int i;
    int result = 0, pos, temp_val;
    int arlen = (int)strlen(h);
    for(i = 0; i < arlen ; ++i){
        if(isdigit(h[i])){
            pos = position(h, arlen, h[i]);
            temp_val = h[i] - '0';
            printf("current: %d, position: %d\n", temp_val, pos);
            result += temp_val * pow(HEX_BASE, pos);
        }
        else{
            pos = position(h, arlen, h[i]);
            temp_val = hex_symbol(h[i]);
            printf("current hex val: %d, position: %d\n", temp_val, pos);
            result += temp_val * pow(HEX_BASE, pos);
        }
    }
    return result;
}

int position(char h[],int len, char a){
    /* find the position of char inside h[]*/
    int i;
    for(i=0; i < len; ++i){
        if(h[i] == a)
            return len - (i + 1);
    }
    return -1;
}

int hex_symbol(char a){
    switch(a){
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            return -1;
    }
}
