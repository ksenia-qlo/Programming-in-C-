/* user:user31
 * name: Ksenia Khlopotina
 * assignment: hw7
 * getop.c
 * gets next token: operator or numeric operand
 */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c;  /* not a number */

  /* collect integer part in string s */
  i = 0;
  if (isdigit(c)) 
    while (isdigit(s[++i] = c = getch()))
      ;
   
  /* collect fractional part in string s */
  if (c == '.') 
    while (isdigit(s[++i] = c = getch()))
      ;
  
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  
  return NUMBER;
}
