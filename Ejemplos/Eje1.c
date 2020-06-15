#include<stdio.h>

int main(void){
    int a[5] = {10, 20, 30, 40, 50};
    int i, *p,*q;
    p = a;
    for(i=0; i<5;i++)
        printf("%d\t%p\n", p[i],p);
    printf("\n");

    q=&a[0];
    for(i=0; i<5; i++){
        printf("%d\t%p\n",*q,q);
        q++;
    }
    printf("\n");

    for(i=0; i<5;i++)
        printf("%d\t", *(a+i));
    printf("\n");

    return 0;
}