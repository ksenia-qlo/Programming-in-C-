/*
 * implement of myAdd() using fullAdderSum() and fullAdderCarry()
 *
 * project: hw4
 * name: Ksenia Khlopotina 
 * user31
 * date:03/11/2019 
 * file: myAdd.c
 * pseudo code:
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include "adder.h"

/*
 * use fullAdderSum() and fullAdderCarry() to add two numbers bit by bit
 * p and q are nonnegative
 * assume their sum does not cause overflow of a 32-bit unsigned int
 */
unsigned int myAdd(unsigned int p, unsigned int q)
{
  enum bits Cin;
  Cin = ZERO;
  int k = 0;

  int mySumInBinary[32];
  for (k = 0; k < sizeof(mySumInBinary)/mySumInBinary[0]; k++) { 
      mySumInBinary[k] = ZERO;  
  }
  /*
   * loop 32 times
   * add a pair of bits from p and q, and the previous carry bit
   * record the sum bit in the corresponding bit in mySum
   * the first carry bit is zero
   * the last carry bit is discarded, assuming no overflow
   */
   int i;
   unsigned int mySum = 0;
   unsigned int carry;
   
   enum bits pbit;
   enum bits qbit;
   enum bits sumbit;
   enum bits carrybit;

   for (i = 0; i < 32; i++) {
    //extract i-th bit from p,q;
    
    //pbit = (p >> i) & 1;
    //qbit = (q >> i) & 1;
    pbit= (p >> i) & ~(~0 << 1);
    qbit= (p >> i) & ~(~0 << 1);
    sumbit = fullAdderSum(pbit, qbit, Cin);
    Cin = fullAdderCarry(pbit, qbit, Cin);
    //mySumBit = (mySum & ~(1 << i)) | (sum << i) & (1 << i);
    /* record the sum bit in the corresponding bit in mySum                       * the first carry bit is zero
     */           
    if (sumbit == ONE)                          
      mySumInBinary[i] = 1; 
    else
      mySumInBinary[i] = 0;
    
    
   mySum = pow(2,i) + mySumInBinary[i];   
   }

   return mySum;
}
