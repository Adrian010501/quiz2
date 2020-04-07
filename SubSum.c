#include <stdint.h>
#include <assert.h>


int SubSum(int x[], int n, int k, int v) {
  if (v == 0 && k == 0) { // Sum and remaining elements = 0;
    return 1;
  } else if (v!=0 && k == 0) {
    return 0;
  } else if (n == 0) {
    return 0;
  }
  int inc = 0;
  if (v >= x[0]) {
    inc = SubSum(x + 1, n - 1, k -1, v - x[0]);
  }
  int dinc = SubSum(x + 1, n - 1, k, v);
  if (dinc || inc) {
    return 1;
  }
  return 0;
}

int main(void) {
  int universal[10000];
  for(int i = 0;i<100;i++){
      universal[i] = i+1;
  }
  assert(!SubSum(universal,100,0,2));
  assert(!SubSum(universal,100,0,1));
  assert(SubSum(universal,100,2,5));
  assert(SubSum(universal,100,2,99));
  assert(SubSum(universal,100,2,80));
  assert(!SubSum(universal,100,2,2));
  assert(!SubSum(universal,0,5,2));
  assert(!SubSum(universal,0,3,1));
return 0;
}
