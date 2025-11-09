#include "q_sort.h"

void swap(double *a, double *b) {
  double tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int divide( double v[], int f, int l ) {
  int s = f;
  f++;

  while( f <= l ) {
    while( f <= l && v[f] < v[s] ) f++;
    while( f <= l && v[l] > v[s] ) l--;
    if( f < l ) {
      swap(&v[f], &v[l]);
      f++;
      l--;
    } else break;
  }

  swap(&v[s], &v[l]);
  return l;
}

void qsort_rec( double v[], int first, int last ) {
  if( first < last ) {
    int m = divide( v, first, last );
    qsort_rec( v, first, m-1 );
    qsort_rec( v, m+1, last );
  }
}

void q_sort( double v[], int n ) {
  qsort_rec( v, 0, n-1 );
}

