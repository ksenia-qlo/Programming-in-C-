/* write comments here
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

static double Ax, Ay;

static int cmpFunc(const void *a, const void *b) {
  
  point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;

  return pa->y < pb->y ? -1:
         pa->y > pa->y ? 1:
         0
         ;
}


static int cmpDeg(const void *a, const void *b) {
  point *pa, *pb;
  double degA, degB;

  pa = (point*) a;
  pb = (point*) b;
  //pa->x, pa->y, pb->x, pb->y
  //figure out how to calculate degree A and degree B
  degA = atan (pa->y/pa->x);
  degB = atan (pb->y/pb->x);          
  return degA < degB ? -1 
         : degA > degB ? 1 
         : 0;
  
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

  qsort(yarray, sizeof(yarray)/ sizeof(yarray[0]), sizeof(double),
		 cmpFunc);
  point A, B;
  point *pa = &A;
  point *pb = &B;
  
 
  //setting max y to point A
  pa->y = yarray[n-1]; 
  
  //matching that y to x of point A
  for (i = 0; i < n; i++) {
    if (dataSet[i].y == pa->y) {
       pa->x = dataSet[i].x;
    }     
  } 
  //at this point we have A
  //shifting points starting with B 
    
  for (i = 1; i < n; i++) {
    if (dataSet[i].x == pa->x && dataSet[i].y == pa->y){
      dataSet[i].x = 0.0;
      dataSet[i].y = 0.0;
    } 
    dataSet[i].x = dataSet[i].x - pa->x;
    dataSet[i].y = dataSet[i].y - pa->y;  
  }
  
   //sorted array of points
  qsort(dataSet, n, sizeof(point),
		                 cmpDeg);
  
  double crossProduct(const void  *a, const void  *b, const void *c) {
    
    point *pa,*pb,*pc;
    pa = (point*) a;
    pb = (point*) b;
    pc = (point*) c;

    double f = pb->x - pa->x;
    double s = pc->y - pa->y;
    double fbys = f * s;
 
    f = pc->x - pa->x;
    s = pb->y - pa->y;
    double fbys2 = f * s;
    return fbys - fbys2;                                       
  }
       
    //making convex hull
   
     
  // point * convexhull = (point *) malloc(sizeof(point) * n);
  //convexhull[0] = dataSet[0];

  // printf("%lf", convexhull[0].x);
  // convexhull[1] = dataSet[1];   
  //printf("%lf", convexhull[0].y);  
  
  //making and initializing array of indices
  int * indices = (int *) malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    indices[i] = i;				 
  } 
  
  
  //index of convexhull                                                              
  int top = indices[2];
  int k;
  point *pc;

  for (i = 0; i < n - 1; i++) {
    point A = dataSet[indices[i]];
    point B = dataSet[indices[i+1]];
    point C = dataSet[indices[top]];
   
    pa = &A;
    pb = &B;
    pc = &C; 
    
    //printf("%lf %lf\n", pc->x, pc->y);
     
    if (crossProduct(pa,pb,pc) > 0)
      printf("Left turn\n");
      //convexhull[top].x = C.x;
      //printf("%lf\n",convexhull[top].x);
      //convexhull[top].y = C.y;
      //printf("%lf\n",convexhull[top].y);
      top++;
       
    if (crossProduct(pc,pb,pc) < 0) {         
      for (k = top; k < sizeof(indices)/sizeof(indices[0]); k++) {
        indices[k-1] = indices[k];
      }     
     
      i--;
      i--;
    }
       
  }
   
  //printing
   
  int ch_size = sizeof(indices);
  printf("%d\n", ch_size);
  printf("Out of %u points, %d vertices are on the convex hull\n", 
	 n, ch_size ) ;
  
  char letter = 'A';
  
  for (i = 0; i < sizeof (indices); i++) { 
    printf("%c (%lf, %lf)\n", letter + indices[i],
	   dataSet[indices[i]].x, dataSet[indices[i]].y);     
  }



}

