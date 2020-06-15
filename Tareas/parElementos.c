/*Luis Kevin Johedan Ramirez Fuentes 30/03/2020*/
#include <stdio.h>

int arr[100];

int encontrarPrimerMenor(int *arr,int x){
    for(int i = 99; i >=0; i--){
        if( *(i+arr) <= x){
            return *(i+arr);
        }
    }
    return -1;
}

int main(){
    for(int a = 0; a<=100; a++){
        arr[a] = a+1; 
    }

    int x;
    printf("Ingresa un numero entero entre 2 y 200: ");
    scanf("%d",&x);

    int num1 = encontrarPrimerMenor(arr,x-1);
    int num2 = encontrarPrimerMenor(arr,x-num1);

    printf("%d es la suma de %d + %d",x,num1,num2);
}

