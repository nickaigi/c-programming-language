#include<stdio.h>

enum gender {
    MALE,
    FEMALE
};

/* - C provides keyword 'typedef' which you can use to give a type a new name
 *      typedef unsigned char BYTE;
 * - After this type definition, the identifier 'BYTE' can be used as an 
 *   abbreviation for the type 'unsigned char' for example:
 *      BYTE b1, b2;
 */
typedef struct student{
    char name[25];
    int age;
    char branch[10];
    enum gender gen;
} Student;

int main(){
    Student s1;

    return 0;
}
