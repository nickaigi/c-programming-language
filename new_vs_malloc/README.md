# What is the difference between new and malloc() in C++ ?

## maloc()

- `malloc()` is a library function of `stdlib.h` and is used in `C` to allocate
memory for N blocks at run time.


## new

- 'new' is an operator in `C++` that is used to declare memory for N blocks at
runtime.



| malloc                                         | new                                                              |
|___________________________________________________________________________________________________________________|
| library function                               | operator                                                         |
| allocates memory and does not call constructor | allocates memore and calls constructor for object initialization |
| returns `void*`                                | returns exact data type                                          |
| slower because its a function                  | faster becasue its an operator                                   |
| call free() to release memory                  | call delete() to free memory                                     |



NB: operators are always faster than functions

[Source](https://www.includehelp.com/cpp-tutorial/difference-between-new-and-malloc.aspx)


# What is the difference between delete() and free() ?

## delete

- `delete` is an operator in `C++` used to free memory allocated by `new`
operator or for a NULL pointer. It also calls the destructor of the class.


## free()

- free is a function used to deallocate memory allocated by `malloc()`

| free                                                 | delete                                                    |
|__________________________________________________________________________________________________________________|
| library function                                     | operator                                                  |
| frees allocated memory, does not call any destructor | frees the allocated memory and calls the class destructor |
| uses `C` run time `CRT` heap                         | may be overloaded on class basis to use private heap      |


