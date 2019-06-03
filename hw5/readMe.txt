a. Pair of m and n such that counting sort is faster than quicksort

The pair when counting sourt if faster is the example from the
test command from our assignment:  -m 64 -n 1048576 

b. Part of m and n such that counting sort is slower than quicksort

The pair when counting sourt is slower than quickSort is
when m is a big number and it is larger than n, example:
-m 99999999 -n 100000

c. Observations:
   I tested around a hundred cases with m and n of different values.
   I saw that in the case when m is smaller than n as per assignment's
   requirement, the counting sort will still outperform the quicksort
   even if the the values of m is extra high but is still smaller than
   n.
   When values of m and n are small, there is not difference in
   milliseconds, both algorithms are very fast.
   
   However, when m gets larger than n, quicksort outperforms the
   counting sort. This happens because the difference between
   the smallest and largest number in the array becomes large.
   It is logical when we consider cases for sorts:
   quicksort's worst case is O(n^2) while average case is O(nlogn)
   cntSort's is O(n+m) so it is linear given that m is less than n.
   But when it is not, m > n and numbers are large, and the closer to
   each other m and n are, the closer the performance of cntSort
   comes to quadratic.  
   
   Another case that stood out was when the m is still large but
   n is much much smaller than m, let's say 2. In this case quicksort
   takes almost no time while cntSort takes significant time.

   
  
>ssss>
