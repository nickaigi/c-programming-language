/* c provides 'typedef' for creating new data type names. E.g.
 *      typedef int Length;
 *
 * makes the name 'Length' a synonym for 'int'. 'Length' can be used in
 * declarations, casts, etc in exactly the same ways that the 'int' type can
 * be:
 *      Length len, maxlen;
 *      Length *lengths[];
 *
 * Similarly, the declaration:
 *      typedef char *String;
 *
 * makes 'String' a synonym for 'char *' or character pointer, which can then
 * be used in declarations and casts:
 *      String p;
 *      int strcmp(String, String);
 *      p = (String) malloc(100);
