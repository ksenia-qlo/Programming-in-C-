/* header file for CS 240 hw3
 *
 * prototypes for functions that perform
 * integer, quaternary, vigesimal conversions
 *
 * modified by Ming Ouyang, Spring 2019
 */

/* function returns in quaternaryStr the char sequence of quaternary
 * digits '0', '1', '2', and '3' used to represent int n.  It is the
 * caller's responsibility to have allocated at least sizeof(int) * 4
 * + 1 char's in quaternaryStr.  itoq must add '\0' at the end of
 * quaternaryStr.
 */
void itoq(char quaternaryStr[], int n); /* source on right, target on left */

/* function returns an integer of the decimal value of the quaternary
 * characters in quaternaryStr.  The function needs to check if
 * quaternaryStr contains only the characters '0', ..., '3'.  It is
 * assumed that quaternaryStr has at most sizeof(int) * 4 quaternary
 * digits.
 */
int qtoi(char quaternaryStr[]); /* return the converted integer */ 

/* function returns in vigesimalStr the char sequence of vigesimal
 * digits '0', ..., '9', 'A', ..., 'J' used to represent int n.  It is
 * the caller's responsibility to have allocated at least sizeof(int)
 * * 2 + 1 char's in vigesimalStr.  itov must add '\0' at the end of
 * vigesimalStr.
 */
void itov(char vigesimalStr[], int n); /* source on right, target on left */

/* function returns an integer of the decimal value of the vigesimal
 * characters in vigesimalStr.  The function needs to check if
 * vigesimalStr contains only the characters '0', ..., '9', 'A', ...,
 * 'J'.  It is assumed that vigesimalStr has at most sizeof(int) * 2
 * vigesimal digits.
 */
int vtoi(char vigesimalStr[]); /* return the converted integer */ 
