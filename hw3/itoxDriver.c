/*
 * stub driver for functions convert between int, quaternary, and
 * vigesimal number
 *
 * project: hw3
 * name: 
 * date: 
 * file: itoxDriver.c
 * notes:
 */

#include <stdio.h>
#include <string.h>
#include "itox.h"

#define LINELEN    1024
#define QUATERNARY (sizeof(int) * 4 + 1)
#define VIGESIMAL  (sizeof(int) * 2 + 1)

int main(void)
{
  char quaternaryStr[QUATERNARY];
  char vigesimalStr[VIGESIMAL];
  char line[LINELEN];
  int m, n;

  /*write a loop here
   * use fgets(line, LINELEN, stdin) to read from keyboard
   * stop the loop if EOF
   * use sscanf(line, "%d", &n) to convert input to int n
   */
  int c;
  while (fgets(line, LINELEN, stdin) != NULL) {
        sscanf(line, "%d", &n);
  //the following 9 lines are the loop body
	itoq(quaternaryStr, n);
	m = qtoi(quaternaryStr);
	printf("input decimal int: %d\n", n);
	printf("quaternary representation: %s\n", quaternaryStr);
	printf("reconverted decimal : %d\n", m);
	itov(vigesimalStr, n);
	m = vtoi(vigesimalStr);
	printf("vigesimal representation: %s\n", vigesimalStr);
	printf("reconverted decimal : %d\n\n", m);
	/*end of loop*/
  }
  return 0;
}


