/*
 * driver for Graham's scan
 * project: hw8
 * name: Ksenia Khlopotina
 * user31
 * date: 05/09/2019
 * file: main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include "point.h"

/* getopt.h */
extern char *optarg;

/* stdlib.h */
extern void srand48(long seed);
extern double drand48(void);

/* graham.c */
extern void graham(point dataSet[], unsigned n);

int main(int argc, char* argv[])
{
  point *dataSet;
  unsigned n, i;
  long seed;
  int c;

  /* command line options
   * ./graham -n nValue -s seedValue
   * n default 32
   * seed default 2019
   */
  n = 32;
  seed = 2019;
  /* process optional command line arguments */
  while ((c = getopt(argc, argv, "n:s:")) != -1) {
    switch (c) {
    case 'n': sscanf(optarg, "%u", &n); break;
    case 's': sscanf(optarg, "%ld", &seed); break;
    default: break;
    }
  }
  printf("n %u, seed %ld\n", n, seed);

  /* seeding the pseudorandom number generator */
  srand48(seed);

  dataSet = (point *)malloc(sizeof(point) * n);
  /* initialize data
   * points are in a circle of radius 1 centered at the origin
   */
  for (i = 0; i < n; i++) {
    dataSet[i].x = drand48() * 2 - 1.0;
    dataSet[i].y = drand48() * 2 - 1.0;
  }

  graham(dataSet, n);

  free(dataSet);
  return 0;
}
