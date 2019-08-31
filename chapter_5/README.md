# Pointers And Arrays

- A pointer is a variable that contains the address of a variable

`&` gives the address of an object

- The expression:

```c
p = &c;
```

assigns the address of `c` to the variable `p` and `p` is said to "point to" `c`

`*` is the `indirection` or the `dereferencing` operator. When applied to a
pointer, it accesses the object the pointer points to
