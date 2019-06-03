/*
 * main.c
 * user: user31
 * name: Ksenia Khlopotina
 * assignment: hw7 
 * reverse polish calculator
 * Pseudocode:
 *            In the postfix notation, the operator is put 
 *            in the last turn. The operands are put on stack
              and perform the operation on them, they are retrieved 
              in the reverse order because of the postfix notation.
              Normally, stack is fifo. With postorder,
              we are retrieving in the reverse order,
              so the first element will be the last one we would receive in
              the regular infix notation we are used to.

              For ex., if there are 2 operands,
              the last one put on stack will be retrieved first.
              With Relational operators, we compare whether the
              comparison is true(1) or false(0).
              With Bitwise operators we push the result of comparison
              back to stack.For unary '~' i reversed each bit of a single 
              pop from stack and pushed it back.
              With Logical Not('!') a zer was returned in case of a non-zero
              number and 1 in case of a 0 for the pop from stack.
              With Ternary operator '?', the macro comparison happens and middle
              operand is returned in case the expression under ? is true,
              and 3d element from pop in case the 1st operand is false.
 *	      
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h" /* header file */

#define MAXOP 128

int main(int argc, char *argv[])
{
  int type;
  //changed double to int as per requirement 
  int op1,op2;
  char s[MAXOP];
  
  while ((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      push(atoi(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else {
	printf("error : zero divisor\n");
	exit(1);
      }
      break;
    //relational operators                                                                                 
    case '>':
      if (pop() < pop())
	push(1);
      else
	push(0);
      break;
    case '<':
      if (pop() > pop())
	push(1);
      else 
        push(0);
      break;
    case '=':
      if (pop() == pop())
	push(1);
      else
	push(0);
      break;
    //bitwise operators
    case '&':
      op1 = pop();
      op2 = pop();       
      push (op1 & op2);
      break;
    case '|':                                                                        
      op1 = pop();
      op2 = pop();   
      push (op1 | op2);
      break;
    case '^':                                               
      op1 = pop();
      op2 = pop();
      push(op1 ^ op2);
      break;
    case '~':
         op1 = pop();
	 push(~op1);
         break;
    case '!':
      //logical operator: 1 for 0 and 0 for non-zero 
      //unary operator
      op1 = pop();
      if (op1 ==0)
	push(1);
      else
	  push(0);
      break;
      //ternary operator
    case '?':
      op1 = pop();
      op2 = pop();
      int op3 = pop();
      if (op1 != 0)
	push(op2);
      else
        push(op3);
      break; 
    case '\n':
      //.8g. Changed the type from double to int
      // in the printf statement
      printf("The answer is %d\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      exit(1);
    }
  }
}
