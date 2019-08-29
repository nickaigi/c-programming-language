# Calculator

C Program calculator that uses reverse Polish Notation.

In reverse Polish notation, each operator follows its operands; an infix expression like:

` (1 - 2) * (4 + 5) `

Is entered as:

` 1 2 - 4 5 + * `

## How to compile:

` $ gcc calc.h main.c getch.c getop.c stack.c `

compiles the files and places the resulting object code in `filename.o` files, then loads them all into an executable file called `a.out`

If there is an error, say in `main.c`, that file can be recompiled by itself and the result loaded with the previous object files with the command:

` gcc main.c getch.o getop.o stack.o`
