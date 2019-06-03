/*
 * driver of counting sort
 *
 * project: hw5
 * name:    Ksenia Khlopotina 
 * user31
 * date:    03/30/2019
 * file: main.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <getopt.h>
#include <sys/time.h>

/* getopt.h */
	extern char *optarg;
/* stdlib.h */
extern void srand48(long seed);
extern double drand48(void);

/* this function is implemented in cntSort.c */
extern void cntSort(unsigned m, unsigned n, unsigned data[]);

/* comparison function for qsort() */
static int cmpUnsigned(const void *a, const void *b)
{
  return *(unsigned *)a - *(unsigned *)b;
}

int main(int argc, char* argv[])
{
  unsigned m, n, *data, *qsorted, i;
  struct timeval start, stop;
  float msec;
  long seed;
  int c;

  /* command line options
   * ./cntSort -m mValue -n nValue -s seedValue
   * m default 64
   * n default 2^20, 1M
   * seed default 2019
   */
  m = 64;
  n = 1 << 20;
  seed = 2019;
  /* process optional command line arguments */
  while ((c = getopt(argc, argv, "m:n:s:")) != -1) {
    switch (c) {
    case 'm': sscanf(optarg, "%u", &m); break;
    case 'n': sscanf(optarg, "%u", &n); break;
    case 's': sscanf(optarg, "%ld", &seed); break;
    default: break;
    }
  }
  printf("m %u, n %u, seed %ld\n", m, n, seed);

  /* seeding the pseudorandom number generator */
  srand48(seed);

  /* allocate memory -- remember to free up them later */
  data =    (unsigned *)malloc(sizeof(unsigned) * n);
  qsorted = (unsigned *)malloc(sizeof(unsigned) * n);

  /* initialize data */
  for (i = 0; i < n; i++)
    qsorted[i] = data[i] = (unsigned) floor(drand48() * m);

  /* time qsort */
  gettimeofday(&start, NULL);
  qsort((void *)qsorted, n, sizeof(unsigned), cmpUnsigned);
  gettimeofday(&stop, NULL);
  msec = (stop.tv_sec - start.tv_sec) * 1000 +
    (stop.tv_usec - start.tv_usec) / 1000;
  printf("quicksort takes %.2f msec\n", msec);

  /* time cntSort */
  gettimeofday(&start, NULL);
  cntSort(m, n, data);
  gettimeofday(&stop, NULL);
  msec = (stop.tv_sec - start.tv_sec) * 1000 +
    (stop.tv_usec - start.tv_usec) / 1000;
  printf("cntSort takes %.2f msec\n", msec);

  /* verify cntSort works correctly */
  for (i = 0; i < n; i++)
    if (data[i] != qsorted[i]) {
      fprintf(stderr, "data differs from qsorted at the %u-th element\n", i);
      exit(1);
    }

  /* free up memory */
  free(qsorted);
  free(data);

  return 0;
}
