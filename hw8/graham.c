/* name: Ksenia Khlopotina
 * user: user31
 * assignment: hw8
 * graham.c
 * Pseudocode: 1. Sort array of y-ccordinates to get the max
               2. Sort array of all points based on angle with origin.
               3. Put points on convex hull based on left or right turns:
                  left with crosporduct being positive and right - for
                  negative crossproduct.
                  I use array of indices to show positions of 3 points
                  to take in for argumnets for crossporduct. If it is the                   left turn, i increment the top. If it is right turn,
                  top is not incremented but all values in the indices
                  array are shifted back by 1. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

static double Ax, Ay;

static int cmpFunc(const void *a, const void *b) {
  
  const double *pa, *pb;
  pa = (const double*) a;
  pb = (const double*) b;
 
 
  return *pa < *pb ? -1:
         *pa > *pb ? 1:
         0
         ;
}


static int cmpDeg(const void *a, const void *b) {
  point *pa, *pb;
  double degA, degB;

  pa = (point *)a;
  pb = (point *) b;
  //pa->x, pa->y, pb->x, pb->y
  //figure out how to calculate degree A and degree B
            
  double hypothenuseA = sqrt(pow(pa->y,2) + pow(pa->x, 2)); 
  double hypothenuseB = sqrt(pow(pb->y,2) + pow(pb->x, 2));
  if (pa->x > 0) {
    degA = 2 * 3.14159265 +  asin(pa->y/hypothenuseA);
  }
  else 
    degA = 3.14159265 - asin(pa->y/hypothenuseA);

  if(pb->x > 0) {
    degB = 2 * 3.14159265 + asin(pb->y/hypothenuseB);
  }
  else
    degB = 3.14159265 - asin(pb->y/hypothenuseB);
  
  // degA = atan2(pa->y,pa->x);
  //degB = atan2(pb->y,pb->x);	      

  return degA < degB ? -1 
         : degA > degB ? 1 
         : 0;
  
}

double myAsin(point a) {
   point * pa;
   pa = &a;
   double degree;
   double hypothenuse = sqrt(pow(pa->y,2) + pow(pa->x, 2));
   if (pa->x > 0) {
     degree = 2 * 3.14159265 + asin(pa->y/hypothenuse);
   }
   else
     degree = 3.14159265 - asin(pa->y/hypothenuse);
   return degree;
}


double crossProduct(point  *a, point  *b, point *c) {
  point *poa,*pob,*poc;
  poa = (point *)a;
  pob = (point *)b;
  poc = (point *)c;
  
  double f = pob->x - poa->x;
  double s = poc->y - poa->y;
  double fbys = f * s;
  double fa = poc->x - poa->x;
  double sa = pob->y - poa->y;
  double fbys2 = fa * sa;
  printf("Cross Product here: %lf", fbys - fbys2);
  return fbys - fbys2;
  
}

/* implement Graham's scan
 * at the end of this function, before returning to main()
 * you should print the vertices of the convex hull counterclockwise
 * starting from the vertex with the largest y-coordinate
 */
void graham(point dataSet[], unsigned n)
{
  /* print the number of vertices on the hull
   * print x- and y-coordinates of the vertices labeled with A, B, C, etc
   */
  
  //making array of y-coordinates of all points
  double * yarray = (double *) malloc(sizeof(double) * n);
  
  int i;
  
  for (i = 0; i < n; i++) {
    yarray[i] = dataSet[i].y;
  }
  qsort(yarray, n, sizeof(double),
		 cmpFunc);
  
  //setting max y to point A
  double max_y = yarray[n-1]; 
  double max_x;
  
  //matching that y to x of point A
  for (i = 0; i < n; i++) {
    if (dataSet[i].y == max_y) {
       max_x = dataSet[i].x;
       printf("Origin's x is %lf\n", max_x);
       printf("Origin's y is %lf\n", max_y);
    }     
  }
  //original array
  //printf("Before sorting\n");                                              
  for(i = 0; i < n; i++) {
     printf("(%lf %lf)\n", dataSet[i].x, dataSet[i].y);                    
  }
 
  //shifting points	   
  for (i = 0; i < n; i++) {
    dataSet[i].x = dataSet[i].x - max_x;
    dataSet[i].y = dataSet[i].y - max_y;  
  }

  //printf("Shift happened\n");
  
  //end array                                                          
  point * dataSet1 = (point *)malloc(sizeof(point) * n);
  //array without origin
  point * dataSet0 = (point *)malloc(sizeof(point) * (n-1));
  
  int flag = 0;

  for(i = 0; i < n; i++) {
    //we skip origin in copying from original array 
    if ((dataSet[i].x == 0.00) && (dataSet[i].y == 0.00)) {
      flag = 1;
      printf("%d\n", i);
      continue;
    }
    //before origin
    if(flag == 0) { 
      dataSet0[i].x = dataSet[i].x;
      dataSet0[i].y = dataSet[i].y;
    }
    //after point of origin
    if (flag == 1) {
      dataSet0[i - 1].x = dataSet[i].x;
      dataSet0[i - 1].y = dataSet[i].y;
    }
 
  }

   //sorted array of points
  qsort(dataSet0, n - 1, sizeof(point),
  		                 cmpDeg);
                  
  for (i = 0; i < n - 1; i++) {
    printf("(%lf %lf)\n", dataSet0[i].x, dataSet0[i].y);
  }
  

  //copying into end array

  dataSet1[0].x = max_x;
  dataSet1[0].y = max_y;

  for (i = 0; i < n - 1; i++) {
     dataSet1[i+1].x = dataSet0[i].x;
     dataSet1[i+1].y = dataSet0[i].y;
  }
  

  printf("End DataSet with Shifted points\n");

  printf("After sorting\n");
 
  for(i = 0; i < n; i++) {
           printf("Degree is %lf Point (%lf, %lf)\n", 
	   myAsin(dataSet1[i]),
	   //  atan2(dataSet1[i].y,dataSet1[i].x),
           dataSet1[i].x, dataSet1[i].y);
  }
  

  //unshifting points                                                        \
  dataSet1[0].x = max_x;
  dataSet1[0].y = max_y;    
  
  for (i = 0; i < n - 1; i++) {
    dataSet1[i+1].x = dataSet0[i].x + max_x;
    dataSet1[i+1].y = dataSet0[i].y + max_y;
  }

  int k;
  point * pa, * pb, * pc;
  point A, B, C;
  pa =&A;
  pb =&B;
  pc =&C;
  
  *pa = A;
  *pb = B;
  *pc = C;
  
  int index = 2;
  int marker = 2;
  point * convexhull = (point *) malloc(sizeof(point) * n);
  convexhull[0] = dataSet1[0];
  convexhull[1] = dataSet1[1];
  
  printf("(%lf %lf) (%lf %lf)\n", convexhull[0].x,
                                  convexhull[0].y,

	                          convexhull[1].x,
      	                          convexhull[1].y);
  
  
  
  //by 1 more for removal procedure
  int numInHull = n + 1;
  //array for copying after removal of 1 element.
  point * temp = (point *)malloc( numInHull * sizeof(point));
  
  for (i = 0; index < n; i++) {
    A = convexhull[i];
    B = convexhull[i+1];
    C = dataSet1[index++];
    printf("Index is %d\n", index);
    printf("(%lf %lf) (%lf %lf) (%lf %lf)", pa->x, pa->y, 
    pb->x, pb->y, pc->x, pc->y);  

    double cp = crossProduct(pa, pb, pc);
    if (cp > 0) {
      
      convexhull[marker] = C; 
      marker++;
     
      printf("This is C: (%lf %lf)\n", pc->x, pc->y);

      printf("Left turn\n");
    }

    if (cp < 0)  {
      printf("Right turn\n");
        //emptying temp
        //last position in temp is always empty because it is by 1 more
        //than n.
      // for (k = numInHull - 2; k <= 0; k--) {                                          
      //    temp[k] = temp[k + 1];                                        
      //  }

      // free(temp);
      //point * temp = (point *)malloc( numInHull * sizeof(point));

      //numInHull--; 
      //printf("%d\n", numInHull);
      marker--;
      
      //for (k = 0; k <= marker; k++) {
      //     convexhull[k] = convexhull[marker]; 
      //	printf("(%lf %lf)\n", convexhull[k].x,convexhull[k].y);
      // }
     
      //memcpy(temp, convexhull, (i + 1) * sizeof(point));
      //copying from remove position forward
      
      //memcpy(temp+i+1, convexhull+i+1+1,
       //where put those: n - remove position gives + 1 for 0
       //gives all mem places left till end of array
       //  ((n+1) - (i+1) - 1) * sizeof(point));

      
      //free(convexhull);
      //*convexhull = *temp; 

      i--;
      i--;
      // }
                                                                                                
       --index;

      for (k = 0; k < marker; k++) {                                                                   
	printf("(%lf %lf)\n", convexhull[k].x,convexhull[k].y);                                                        
      }      
     }
  }
  /*    

    //making convex hull
       
  int * indices = (int *) malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    indices[i] = i;				 
  } 
  
                                                               
  int top = indices[2];
  int k;
  point * pa, * pb, * pc;
  point A, B, C;
  pa = &A;
  pb = &B;
  pc = &C;

       
  for (i = 0; i < n - 1 ; i++) {
    
    A = dataSet1[indices[i]];
    B = dataSet1[indices[i+1]];
    
    if (top != (n - 1)) { 
      C = dataSet1[indices[top]]; 
      printf("(%lf   %lf)\n",  pc->x, pc->y);
    }    
    else { 
      C = dataSet1[indices[0]]; 
      printf("(%lf   %lf)\n",  pc->x, pc->y);
    }
    
    char letter = 'A';
    printf("(%lf %lf) (%lf %lf) (%lf %lf)", pa->x, pa->y, 
	   pb->x, pb->y, pc->x, pc->y);
    if (crossProduct(pa, pb, pc) > 0) {
      printf("%c", letter + indices[i]);
      printf("%c", letter + indices[i +1]);
      printf("%c", letter + top);
        printf("Left turn\n");
        top++;
    }
    if ((crossProduct(pa, pb, pc) < 0) ) {         
      printf("Right turn\n");
         printf("%c", letter + indices[i]);
         printf("%c", letter + indices[i + 1]);
         printf("%c", letter + top);       
      for (k = top; k < sizeof(indices); k++) {
         indices[k-1] = indices[k];
         indices[k] = -1;
      }     
       i--;
       i--;
    }
       
  }
  
  

  //printing
   
  int count = 0;
  for(i = 0; i < sizeof(indices); i++) {
    if (indices[i]!=-1) {
      count++;
    }
  }
 
 
  //int count = 0;
  //printf("Out of %u points, %d vertices are on the convex hull\n", 
  //
  	 n, count) ;
  */
  char letter = 'A';
  
  for (i = 0; i < marker; i++) { 
     printf("%c (%lf, %lf)\n", letter + i,
     convexhull[i].x, convexhull[i].y);     
  }
  
}



