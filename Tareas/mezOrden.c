/*Luis Kevin Johedan Ramirez Fuentes 30/03/2020*/
#include <stdio.h>

int n,m;

int arr1[1000],arr2[1000],res[1000];

int main(){
    printf("Ingresa la cantidad de numeros del primer arreglo: ");
    scanf("%d",&n);
    printf("Ingresa los numeros del primer arreglo:\n");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr1[i]);
    }

    printf("Ingresa la cantidad de numeros del segundo arreglo: ");
    scanf("%d",&m);
    printf("Ingresa los numeros del segundo arreglo:\n");
    for(int i = 0; i<m; i++){
        scanf("%d",&arr2[i]);
    }

    int i = 0, j = 0;
    while(i<n && j <m){
        if(arr1[i] < arr2[j]){
            res[i+j] = arr1[i];
            i++;
        }else{
            res[i+j] = arr2[j];
            j++;
        }
    }

    for(int a = i; a<n; a++){
        res[j+a] = arr1[a];
    }
    for(int a = j; a<m; a++){
        res[i+a] = arr2[a];
    }


    printf("Los arreglos mezclados son: ");
    for(int a=0; a<n+m; a++){
        printf("%d ",res[a]);
    }
}