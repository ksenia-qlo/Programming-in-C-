/* name: Ksenia Khlopotina
 * user: user31
 * assignment: hw7
 * getch.c
 * getch returns one character from stdin 
 * or from the buffer buf if it is not empty
 * ungetch puts one character in the buffer buf 
 */

#include <stdio.h>

#define BUFSIZE 1024
static char buf[BUFSIZE] ;  /* buffer for ungetch */
static unsigned bufTop = 0; /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void)
{
  return (bufTop > 0) ? buf[--bufTop] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
  if (bufTop >= BUFSIZE) {
    fprintf(stderr, "ungetch: buffer full\n");
    exit(1);
  }
  else
    buf[bufTop++] = c;
}
