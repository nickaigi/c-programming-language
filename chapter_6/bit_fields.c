/* When storage space is at a premium, it may be necessary to pack several
 * objects into a single machine word; one common use is a set of single-bit
 * flags in applications like compiler symbol tables.
 *
 * The usual way this is done is to define a set of "masks" corresponding
 * to the relevant bit positions, as in
 */
#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

// or
enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

/* the numbers must be powers of 2. Accessing the bits becomes a matter of
 * "bit-fiddling" with the shifting, masking and complementing operators
 * described in Chapter 2
 */
