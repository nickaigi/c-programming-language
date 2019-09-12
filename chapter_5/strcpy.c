#include<stdio.h>

void mystrcpy(char*, char*);

int main() {
    char s[] = "nickson";
    char t[7];
    mystrcpy(s, t);
    return 0;
}

/* strcpy: copy t to s; array subscript version */
void mystrcpy(char *s, char *t) {
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}
