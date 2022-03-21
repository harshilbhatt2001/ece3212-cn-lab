#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[50], t1[70], t2[70];
  int i, j, t, n, nh, d, k, pos = 0, sum = 0, maxp = 6, m;
  printf("Enter Length Of Data String: ");
  scanf("%d", &d);
  printf("Enter Data String: ");
  for (i = 0; i < d; i++) {
    scanf("%d", &a[i]);
  }
  printf("\n***************************************\n");
  for (i = 0, j = 0; i < d; i++) {
    for (k = 0; k < maxp; k++) {
      t = pow(2, k) - 1;
      if (j == t) {
        t1[j] = 0;
        j++;
      }
    }
    t1[j] = a[i];
    j++;
  }
  nh = j;
  printf("Length of Hamming code: %d bits\n", nh);
  n = nh - d;
  printf("Number of Parity Bits (Redundant bits): %d \n", n);
  int b[n];
  m = n - 1;
  for (k = 0; k < n; k++) {
    t = pow(2, k) - 1;
    for (i = t; i < nh;) {
      for (j = 0; j <= t; j++) {
        sum = sum + t1[i];
        i++;
        if (i >= nh) {
          break;
        }
      }
      if (i >= nh) {
        break;
      }
      for (j = 0; j <= t; j++) {
        i++;
        if (i >= nh) {
          break;
        }
      }
      if (i >= nh) {
        break;
      }
    }
    t1[t] = sum % 2;
    sum = 0;
    printf("P%d: %d ", t + 1, t1[t]);
  }
  printf("\n\nHamming code on Sender side: ");
  for (i = 0; i < nh; i++) {
    printf("%d ", t1[i]);
  }
  printf("\nHamming code on Receiver side: ");
  for (i = 0; i < nh; i++) {
    scanf("%d", &t2[i]);
  }
  sum = 0;
  for (k = 0; k < n; k++) {
    t = pow(2, k) - 1;
    for (i = t; i < nh;) {
      for (j = 0; j <= t; j++) {
        sum = sum + t2[i];
        i++;
        if (i >= nh) {
          break;
        }
      }
      if (i >= nh) {
        break;
      }
      for (j = 0; j <= t; j++) {
        i++;
        if (i >= nh) {
          break;
        }
      }
      if (i >= nh) {
        break;
      }
    }
    b[m] = sum % 2;
    sum = 0;
    printf("P%d: %d ", t + 1, b[m]);
    m--;
  }
  for (m = 0; m < n; m++) {
    pos = pos + b[n - m - 1] * pow(2, m);
  }
  printf("\n\nError is at position: %d\n", pos);
  if (t2[pos - 1] == 0) {
    t2[pos - 1] = 1;
  } else {
    t2[pos - 1] = 0;
  }
  printf("Hamming code: Receiver side: Error Corrected: ");
  for (i = 0; i < nh; i++) {
    printf("%d ", t2[i]);
  }
}