#include "safeint.h"

/* Reverses a string. You must provide the str
   length yourself because in the end systems
   will be faster if they keep track of a single
   length for each particular string that needs
   length kept track of it.
 */
void reversestring(char* str, uint32 strlength) {
	--strlength;
	uint32 beg = 0;
	for (;beg < strlength; ++beg, --strlength) {
		char tmp = str[beg];
		str[beg] = str[strlength];
		str[strlength] = tmp;
	}
}

/* Get the length of a string in a uint32
 */
uint32 strlen(const char* str) 
{
	uint32 len = 0;
	while (str[len])
		len++;
	return len;
}

/* Convert a 32 bit integer to a null terminated string
 * If you put in too small of a buffer for your large
 * integer it will just keep on writing chars lol
 */
void i32toa(char* buffer, int32 integer) {
	uint32 digcount = 0;
	while (1) {
		buffer[digcount++] = (integer % 10) + 48;
		integer /= 10;
		if (!integer) {
			break;
		}
	}
	reversestring(buffer, digcount);
	buffer[digcount] = '\0';
}