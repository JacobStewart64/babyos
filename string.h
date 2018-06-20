#include "safeint.h"

/* Reverses a string. You must provide the str
   length yourself because in the end systems
   will be faster if they keep track of a single
   length for each particular string that needs
   length kept track of it.
 */
void reversestring(char* str, uint32 strlength);

/* Get the length of a string in a uint32
 */
uint32 strlen(const char* str);

/* Convert a 32 bit integer to a null terminated string
 * If you put in too small of a buffer for your large
 * integer it will just keep on writing chars lol
 */
void i32toa(char* buffer, int32 integer);