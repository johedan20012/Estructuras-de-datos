#include <stdio.h>

int main() {
const int x = 5;
int *prt;
prt = &x;
*prt = 10;
printf("%d", x);
}