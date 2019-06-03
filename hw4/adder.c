/*
 * implement fullAdderSum() fullAdderCarry()
 *
 * project: hw4
 * name: Ksenia Khlopotina 
 * user31
 * date: 03/11/2019
 * file: adder.c
 * pseudo code:
 * notes:
 */

#include "adder.h"

/*
 * add two bits P and Q
 * return the sum bit
 */
enum bits halfAdderSum(enum bits P, enum bits Q)
{
  return P ^ Q;
}

/*
 * add two bits P and Q
 * return the carry bit
 */
enum bits halfAdderCarry(enum bits P, enum bits Q)
{
  return P & Q;
}

/*
 * add three bits P, Q, and Cin
 * return the sum bit
 */
enum bits fullAdderSum(enum bits P, enum bits Q, enum bits Cin)
{
  //enum bool {TRUE,FALSE};
  if
    //exclusive or
  (((halfAdderSum(Q,P)==ONE ||                                                             
     halfAdderSum(Q,Cin)== ONE ||                   
     halfAdderSum(P,Cin) == ONE)
     &&                                      
     fullAdderCarry(P, Q, Cin) == ZERO) 
   ||
   ( halfAdderCarry(Q,Cin)== ONE &&
     halfAdderCarry(P,Cin) == ONE &&
     fullAdderCarry(P, Q, Cin) == ONE))

    return ONE;
  else
    return ZERO;
   
}

/*
 * add three bits P, Q, and Cin
 * return the carry bit
 */
enum bits fullAdderCarry(enum bits P, enum bits Q, enum bits Cin)
{
  if 
    (halfAdderCarry(Q,P)==ONE ||
     halfAdderCarry(Q,Cin)==ONE ||                                                           
     halfAdderCarry(P,Cin)==ONE)
    return ONE;
  else
    return ZERO;
}


