/*
 * functions that convert between int, quaternary, and vigesimal numbers
 * 
 * project: hw3
 * name:    Ksenia Khlopotina
 * date:    03/03/2019
 * file:    itox.c
 * notes:   		
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "itox.h"
#define QUART 4
#define VIG 20
extern char quarternaryStr[];
extern char vigesimalStr[];

/* function converts int n to a quaternary string in the
   hexstring array */
void itoq(char quaternaryStr[], int n)
{
  //decimal representation
  int q = 0;
  int r = 0;
  int i;
  
  q = n / QUART;
  r = n % QUART;
  
  //char *p;
  //*p = quaternaryStr[0];
 
  //int v = sizeof(int) * 4 + 1;
  //quaternaryStr[v] = { 0 };
  if (r == 0)
    quaternaryStr[sizeof(int) * 4 - 1] = '0';
  if (r == 1)
    quaternaryStr[sizeof(int) * 4 - 1] = '1';
  if (r == 2)
    quaternaryStr[sizeof(int) * 4 - 1] = '2';
  if (r == 3)
    quaternaryStr[sizeof(int) * 4 - 1] = '3';
  
  // printf("%c", quaternaryStr[sizeof(int) * 4 - 1]);

  for (i = sizeof(int) * 4 - 2; i >= 0; i--) {
    r = q % QUART;
    if (r == 0) 
      quaternaryStr[i] = '0';
    if (r == 1)
      quaternaryStr[i] = '1';
    if (r == 2)
      quaternaryStr[i] = '2';
    if (r == 3)
      quaternaryStr[i] = '3';
    q = q / QUART;
    // printf("%c", quaternaryStr[i]);
  }
  quaternaryStr[sizeof(int) * QUART] = '\0';

  printf("%s", quaternaryStr);
}
/* function converts a quaternary string to its int value  */
int qtoi(char quaternaryStr[])
{ 
 
  int i;
  
  int intArray [sizeof(int) * 4];
  
  for(i = 0; i < sizeof(int) * 4; i++) {
    intArray[i] = 0;
  }

  for (i = 0; i < sizeof(int) * 4; i++) {
    if (quaternaryStr[i] == '0') 
      intArray[i] = 0; 
    if (quaternaryStr[i] == '1') 
      intArray[i] = 1;
    if (quaternaryStr[i] == '2') 
      intArray[i] = 2;
    if (quaternaryStr[i] == '3') 
      intArray[i] = 3;  
    //if (quaternaryStr[i] == '\0')
    //  break;
  }   
 
  int n = 0;
  for (i = sizeof(int) * 4 - 1; i >= 0; i--) {  		
    printf("IntArray %d\n", intArray[i]);
    n += intArray[i] * pow(QUART, (sizeof(int) * 4 - 1)- i);
    
    printf("Sum %d\n", n);                     
  }
  return n;
}

/* function converts int n to a vigesimal string in the
   hexstring array */

void itov(char vigesimalStr[], int n)
{  
   int q = 0;
   int r = 0;
   int i;
   
   q = n / VIG;
   r = n % VIG;
   //char *p;
   //*p = vigesimalStr[0];
   //vigesimalStr[sizeof(int) * 2 + 1] = { };

   if (r == 0)
     vigesimalStr[sizeof(int) * 2 - 1] = '0';
   if (r == 1)
     vigesimalStr[sizeof(int) * 2 - 1] = '1';
   if (r == 2)
     vigesimalStr[sizeof(int) * 2 - 1] = '2';
   if (r == 3)
     vigesimalStr[sizeof(int) * 2 - 1] = '3';
   if (r == 4)
     vigesimalStr[sizeof(int) * 2 - 1] = '4';
   if (r == 5)
     vigesimalStr[sizeof(int) * 2 - 1] = '5';
   if (r == 6)
     vigesimalStr[sizeof(int) * 2 - 1] = '6';
   if (r == 7)
     vigesimalStr[sizeof(int) * 2 - 1] = '7';
   if (r == 8)
     vigesimalStr[sizeof(int) * 2 - 1] = '8';
   if (r == 9)
     vigesimalStr[sizeof(int) * 2 - 1] = '9';
   if (r == 10)
     vigesimalStr[sizeof(int) * 2 - 1] = 'A';
   if (r == 11)
     vigesimalStr[sizeof(int) * 2 - 1] = 'B';
   if (r == 12)
     vigesimalStr[sizeof(int) * 2 - 1] = 'C';
   if (r == 13)
     vigesimalStr[sizeof(int) * 2 - 1] = 'D';
   if (r == 14)
     vigesimalStr[sizeof(int) * 2 - 1] = 'E';
   if (r == 15)
     vigesimalStr[sizeof(int) * 2 - 1] = 'F';
   if (r == 16)
     vigesimalStr[sizeof(int) * 2 - 1] = 'G';
   if (r == 17)
     vigesimalStr[sizeof(int) * 2 - 1] = 'H';
   if (r == 18)
     vigesimalStr[sizeof(int) * 2 - 1] = 'I';
   if (r == 19)
     vigesimalStr[sizeof(int) * 2 - 1] = 'J';  
  
   //printf("%c", vigesimalStr[sizeof(int) * 2 - 1]);
   for (i = sizeof(int) * 2 - 2; i >= 0; i--) {
     r = q % VIG;
     if (r == 0)
       vigesimalStr[i] = '0';
     if (r == 1)
       vigesimalStr[i] = '1';
     if (r == 2)
       vigesimalStr[i] = '2';
     if (r == 3)
       vigesimalStr[i] = '3';
     if (r == 4)
       vigesimalStr[i] = '4';
     if (r == 5)
       vigesimalStr[i] = '5';
     if (r == 6)
       vigesimalStr[i] = '6';
     if (r == 7)
       vigesimalStr[i] = '7';
     if (r == 8)
       vigesimalStr[i] = '8';
     if (r == 9)
       vigesimalStr[i] = '9';
     if (r == 10)
       vigesimalStr[i] = 'A';
     if (r == 11)
       vigesimalStr[i] = 'B';
     if (r == 12)
       vigesimalStr[i] = 'C';
     if (r == 13)
       vigesimalStr[i] = 'D';
     if (r == 14)
       vigesimalStr[i] = 'E';
     if (r == 15)
       vigesimalStr[i] = 'F';
     if (r == 16)
       vigesimalStr[i] = 'G';
     if (r == 17)
       vigesimalStr[i] = 'H';
     if (r == 18)
       vigesimalStr[i] = 'I';
     if (r == 19)
       vigesimalStr[i] = 'J';
     q = q / VIG;
     //printf("%c", vigesimalStr[i]);
   }

   vigesimalStr[sizeof(int) * 2] = '\0';
   
   printf("%s", vigesimalStr);     
}
 
/* function converts a vigesimal string to its int value  */
int vtoi(char vigesimalStr[])
{ 
  int i;
  int intArray[sizeof(int) * 2];
  
  for(i = 0; i < sizeof(int) * 2; i++) {
    intArray[i] = 0;
  }

  for (i = 0; i < sizeof(int) * 2; i++) {
     if (vigesimalStr[i] == '0')
       intArray[i] = 0;
     if (vigesimalStr[i] == '1')
       intArray[i] = 1;
     if (vigesimalStr[i] == '2')
       intArray[i] = 2;
     if (vigesimalStr[i] == '3')
       intArray[i] = 3;
     if (vigesimalStr[i]== '4')
       intArray[i] = 4;
     if (vigesimalStr[i] == '5')
       intArray[i] = 5;
     if (vigesimalStr[i]== '6')
       intArray[i] = 6;
     if (vigesimalStr[i]== '7')
       intArray[i] = 7;
     if (vigesimalStr[i]== '8')
       intArray[i] = 8;
     if (vigesimalStr[i]== '9')
       intArray[i] = 9;
     if (vigesimalStr[i] == 'A')
       intArray[i] = 10;
     if (vigesimalStr[i] == 'B')
       intArray[i] = 11;
     if (vigesimalStr[i] == 'C')
       intArray[i] = 12;
     if (vigesimalStr[i] == 'D')
       intArray[i] = 13;
     if (vigesimalStr[i] == 'E')
       intArray[i] = 14;
     if (vigesimalStr[i] == 'F')
       intArray[i] = 15;
     if (vigesimalStr[i] == 'G')
       intArray[i] = 16;
     if (vigesimalStr[i] == 'H')
       intArray[i] = 17;
     if (vigesimalStr[i] == 'I')
       intArray[i] = 18;
     if (vigesimalStr[i] == 'J')
       intArray[i] = 19;
   }
 
   int n = 0;
 
   for (i = sizeof(int) * 2 - 1; i >= 0;  i--) {
     n += intArray[i] * pow(VIG, (sizeof(int) * 2 - 1) - i);
   }
   return n;
}  
 
