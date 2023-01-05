#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid + 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int binsearch_2(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low != high) {
    mid = low + high / 2;
    if (v[mid] > x) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  if (v[low] == x) {
    return low;
  }
  return -1;
}

int main() {
  const int n = 10;
  int arr[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  clock_t t = clock();
  const int res = binsearch(9, arr, 10);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("time taken for original: %f\n", time_taken);
  t = clock();
  const int res2 = binsearch_2(9, arr, 10);
  t = clock() - t;
  double time_taken_2 = ((double)t) / CLOCKS_PER_SEC;
  printf("time taken for improved: %f\n", time_taken_2);
  assert(res == 7);
  assert(res2 == 7);
}
