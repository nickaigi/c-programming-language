/* this code is typical of what might be found in the symbol table
 * management routines of a macro processor or a compiler
 *
 * for example, consider the
 *
 *      #define IN 1
 * is encountered, the name IN and the replacement text 1 are stored in a table
 * Later, when the name IN appears in a statement like
 *      state = IN;
 *
 * it must be replaced by 1.
 */
