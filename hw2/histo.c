/*
 * Project: hw2
 * Name   : Ksenia Khlopotina
 * Date   : 02/10/2019
 * File   : histo.c
 * Notes  : The program represents a historgram of word-length buckets. 
 * Each bucket has words of one length. There are 27 such groups, 
 * each is represented by a new line in the output. Line starts with word 
 * count in group, then space, then "*"-s to show for each 4000 words.
 */
 

#include <stdio.h>
#define STAR 4000
/*
 * The function is: 1. counting how many words in 1 group
 * (having same number of letters) are there in a file.
 * 2. making a picture of count in 1 group with a number, space and
 * "*"-s. Each "*" represents 4000 or less words.
 * Args    : nothing
 * Returns : 0
 */
int main(void) 
{  /*
    * array counts number of words of one length.
    * There are words of 1-27                                
    * characters in length --> 27 groups.
    */
   int wordsInGroupCount [28];
   int k; /* iterator inside word */
   int c;/* individual character */
   k = 0;
   c = 'c';
   int j;
   for (j=1; j < 28;j++) {
     wordsInGroupCount[j] = 0;
   }
   /*
    *  1st loop checks for EOF.
    * 2d loop checks for end of word.
    * k variable is a counter for leters in a word.
    * wordsInGroupCount counts instances of  n-th letter words binding
    * them into 1 group in an array wordsInGroupCount.
    * There are 27 groups based on 27 different word lengths from 1 to 27 
    * chars.
    */
   while ((c = getchar()) != EOF) { 
     /* if the char is alphanumeric */  
     // if (isalnum(c)!=0) {   
     if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
	 (c >= 0 && c <= 9)) {
     k++;      
     }
     /*add 1 to count of words in respective groups based on lenghts*/
     else {
       wordsInGroupCount[k] = wordsInGroupCount[k] + 1;
       /*adding to total word count*/
       /*resetting count of characters for new word*/
       k = 0;
     }
   }
   /*Starting histogram part of the program.*/
   /*k represents length, as usual, and printed on line.*/
   int numStars;
   numStars = 0;

  for (k = 1; k < 28; k++) {
    
    numStars = (wordsInGroupCount[k]/STAR) + 1; 
    printf("%d ", k);
    printf("%d", wordsInGroupCount[k]);
     if (wordsInGroupCount[k] !=0) {        
       for (numStars = numStars; numStars > 0; numStars--) {
    	printf("*");  
       }
     }
    printf("\n"); 
  }
  return 0;
}

