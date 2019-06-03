
 /*
  * project: hw6
  * name: Ksenia Khlopotina 
  * user31
  * date: 04/07/2019
  * file: tail.c
  * pseudocode: 1. Parse -n option for the number of lines to 
                   display for tail. If -n is not entered as 1-st 
                   index argument, then assign default value for n.
                   Account for negative, wrong inputs, as well as 0 
                   value for n that makes the program exit.         
                2. Read from input file line, check the number of 
                   current line in file. If it exceeds index 2000,
                   remove first line in pointer array, place it
                   current line in last index and move all indices 
                   up by 1.
                   If the current line index is less than 2000,
                   calculate actual length of current line, 
                   allocate memory for this pointer in pointer array
                   by assigning the calculated length, copy
                   the current line from buffer into string 
                   pointed to by this new pointer. Save this newly
                   allocated pointer in a pointer array.
                   Index of pointer in this array refers to
                   the same index in the order of lines we 
                   were reading from file that was updated
                   dynamically if file is larger than
                   the maximum of 2000. 
                3. Calculate start index for tail printout
                   by deducting n option from maximum, 2000.    
                4. Print tail lines pointed to by pointer array.
                5. Free up memory assigned for pointer array.      
  */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <getopt.h>

 extern char *optarg;
 #define BUFFER_l 1024
 #define DEFAULT_LINES 10
 #define MAXLINE 2000
 
 /* hold characters of 1 line */
 char buffer[BUFFER_l];

 char *lineptr[MAXLINE]; 
 int main(int argc, char *argv[]) {
   
 int n = 0;
 int c;

 //reading command line argument for -n option:
 if (argc > 1 && (strcmp(argv[1],"-n") == 0)) {
   while ((c = getopt(argc, argv, "n:")) != -1) {
     switch(c) {    
       case 'n': sscanf(optarg, "%d", &n); break;
       default: break;
     }   
    }
    if (n  > 0 && n <= MAXLINE)                                                              
      ;                                                                                       
    else if (n == 0)                                                                          
      return 0;                                                                              
    else if (n < 0) {                                                                          
      printf("Negative n!\n");
      return 0;      
    }                                                         
    else if (n > MAXLINE) {                                                                    
      printf("n has to be <= 2000\n");
      return 0;            
    } 
  }
  else if (argc > 1 && (strcmp(argv[1],"-n") != 0))                
    n = DEFAULT_LINES;                        
  else {                 
    printf("man tail to refere to syntax of tail!\n");                                            	 
    return 0;
  }
  //printf("%d", n); 
  
  int len = 0;
  int i = 0;

  while (fgets(buffer, BUFFER_l, stdin) != NULL) {
    len = strlen(buffer) + 1;
    //printf("%d", len);
    if (i == MAXLINE) {
      for (i = 1; i < MAXLINE;i++) {
	lineptr[i - 1] = lineptr[i];// 1999 --> l998 etc.        
      }
      free(lineptr[0]);
      i--; //has to be 1999 
    }
    //allocate memory for 1 line;      
    lineptr[i] = (char *) malloc(sizeof(char) * len); 
    strcpy(lineptr[i], buffer);
    i++;
  }
  //printf("%d\n", i);
  int start = i - n;
   
  for (i = start; i < MAXLINE; i++) {
    printf("%s", lineptr[i]);
  }
  for (i = 0; i < MAXLINE; i++){
    free(lineptr[i]);
  }  
  return 0;
 }

 
