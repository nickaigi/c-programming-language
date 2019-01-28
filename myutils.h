/* we use conditional define to avoid redefination of this header file */
#ifndef myutils
/* if not defined, execute the statements below */
int power(int base, int xp){
    if (xp < 1)
        return 1;
    else
        return base * power(base, xp - 1);
}
#define myutils /* then define myutils. consider power as defined */
#endif /* end the if statement */
