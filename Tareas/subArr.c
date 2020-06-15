/*Luis Kevin Johedan Ramirez Fuentes 30/03/2020*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[1000];
int ini = 0,fin = 0;

int main(){
    srand(time(NULL));

    for(int a=0 ; a<1000; a++){
        arr[a] = rand()%1000;
    }

    for(int a=0; a<999; a++){
        if(arr[a] == arr[a+1]-1){
            int ind = a+1;
            while(ind <999){
                if(arr[ind] != arr[ind+1]-1){
                    break;
                }

                ind++;
            }
            ini = a;
            fin = ind;
            break;
        }
    }

    if(fin == 0){
        printf("No hay un subarreglo con numeros consecutivos\n");
        return 0;
    }

    printf("Un subarreglo con numeros consecutivos es: \n");
    for(int a = ini; a<=fin; a++){
        printf("%d ",arr[a]);
    }
    printf("\nCon sus indices en el arreglo orignal: \n");
    for(int a = ini; a<=fin; a++){
        printf("%d ",a);
    }
    return 0;
}