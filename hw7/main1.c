/*
 * main.c
 *
 * reverse polish calculator
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h" /* header file */

#define MAXOP 128

int main(int argc, char *argv[])
{
  int type;
  //was double before 
  int op1,op2;
  char s[MAXOP];
  int j,r,q = 0;
  int * binary0 = (int *)malloc(sizeof(int) * 32);
  int * func(int q) {
     while (q !=0) {
      r = q % 2;
      q = q / 2;
      binary0[j] = r;
      j++;
     }
   int i = 0;
   //reverse binary because for int->binary conversion                                                                         
   //we needed to record from right to left.                                                                                   
  //we did left to right, now need to reverse.                                                                                
  for (r = j - 1; r >=0; r--) {
    binary0[i] = binary0[r];
    i++;
  }
  return binary0;
  }
 
  int * number;
  int * binary1; 
  int * binary2;
  int result,i;


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
      if (pop() > pop())
	push(1);
      else
	push(0);
      break;
    case '<':
      if (pop() < pop())
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
      //new code
      op1 = pop();
      op2 = pop();                                                                    
      
      binary1 = func(op1);
      free(binary0);
      binary2 = func(op2);
      free(binary0);
      for ( i = 0; i = sizeof(binary1)/sizeof(int); i++) {
	 if (binary1[i]==binary2[i]==1) 
	   number[i] = 1;
	 else
	   number[i] = 0;	  
      }
      //binary to decimal
      int result = 0;
      for ( i = 0; i = sizeof(number)/sizeof(int); i++) {
        result += number[i] * pow(2,i);     
      }
      push(result);
      break;
    case '|':
             //new code                                                                        
         op1 = pop();
         op2 = pop();   
         binary1 = func(op1);
         free(binary0);
         binary2 = func(op2);
         free(binary0);
         for (i = 0; i = sizeof(binary1)/sizeof(int); i++) {
           if (binary1[i]+binary2[i]==1) 
	     number[i]=1;
          else
	    number[i] = 0;
         }
	      //binary to decimal                                                                                                          
	  result = 0;
	  for ( i = 0; i = sizeof(number)/sizeof(int); i++) {

          result += number[i] * pow(2,i);

          }
	  push(result);
	  break;
    case '^':
      //new code                                                                                            
            op1 = pop();
            op2 = pop();
            //into binary                                                             
           binary1 = func(op1);
           free(binary0);
           binary2 = func(op2);
           free(binary0);
         for (i = 0; i = sizeof(binary1)/sizeof(int); i++) {
            if (binary1[i]+binary2[i]==1 ||binary1[i]+binary2[i]==0 ) 
	      number[i] = 1;
          else
	    number[i] = 0;
	 }
	 //binary to decimal                                                                                                          
	 result = 0;
	 for ( i = 0; i = sizeof(number)/sizeof(int); i++) {

          result += number[i] * pow(2,i);

          }
	  push(result);
         
	  break;
    
    case '~':
         op1 = pop();
         op2 = pop();
         binary1 = func(op1);
         free(binary0);
         binary2 = func(op2);
         free(binary0);
         for (i = 0; i = sizeof(binary1)/sizeof(int); i++) {
            if (binary1[i]!= binary2[i] )
                 number[i] = 1;
            else
	         number[i]=0;
	 }     
	         //binary to decimal                                                                                                          
	 result = 0;
	 for ( i = 0; i = sizeof(number)/sizeof(int); i++) {

         result += number[i] * pow(2,i);

         }
	 push(result);

         break;
    case '!':
      //logical operator: 1 for 0 and 0 for non-zero 
      //ternary operator
      op1 = pop();
      if (op1 ==0)
	push(1);
      else
	  push(0);
      break;
    case '?':
      op1 = pop();
      op2 = pop();
      int op3 = pop();
      if (op3 != 0)
	push(op1);
      else
        push(op2);
      break; 
    case '\n':
      //??.8g.
      printf("The answer is %lf\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      exit(1);
    }
  }
}
