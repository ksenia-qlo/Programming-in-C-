/*
 * implementation of counting sort
 *
 * project: hw5
 * name:    Ksenia Khlopotina
 * user31
 * date:    03/31/2019
 * file: cntSort.c
 * pseudo code: 1. populate array count with 0-s.
                2. iterate through array data and put 
                   elements of data into indices of count 
                   array. Each time we come to same index for
                   count, the value for this element is count
                   gets incremented by one. This way we count
                   the number of elements for same index
                   in count.
                3. We overwrite array data with indices 
                   from count.They are bound by m and we go
                   from 0 to m - 1.
                   Whenever a new element is put into 
                   new data array, we decrement values
                   in count for that index by 1.
                   When value reaches 0, we increment index
                   for count, decrement i to account for 
                   incrementing at ened of for cycle, not to miss
                   any position in data.
                   This way we arrive at a new sorted data array.  
 * notes:
 */

#include <stdlib.h>

void cntSort(unsigned m, unsigned n, unsigned data[])
{
  unsigned *count;
  // unsigned *cntSort;
  /* allocate memory */
  count = (unsigned *)malloc(sizeof(unsigned) * m);
  // cntSort = (unsigned *)malloc(sizeof(unsigned) * n);
  /* shall sort to: [0,0,0,1,1,1,1,2,2,2] */

  int i;
  int num = 0;
 
  for (i = 0; i < m; i++) {
    count[i] = 0;
    // printf("%u", count[i]);
  }
  
  int count_index = 0;

  for (i = 0; i < n; i++) {    
    count[data[i]] = count[data[i]] + 1;
    // printf("%u", count[data[i]]);
  }
  
  count_index = 0;

  for ( i = 0; i < n; i++) {
    //how many times to print each element
    //if not print 0 times:
      if (count[count_index]!=0) { 
	data[i] = count_index;
        count[count_index] = count[count_index] - 1;
	//  printf("%u", data[i]);    
      }
      else {
	count_index++;
        i--;
      }
  }
  /* free up memory */
  free(count);
}



