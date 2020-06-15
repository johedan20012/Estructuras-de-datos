#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pila.h"
#include "cola.h"
#include "listaEnlazada.h"

int main(){
    srand(time(NULL));

    Pila* miPila = PilaNueva();

    miPila->push(miPila,1);
    miPila->push(miPila,2);
    miPila->push(miPila,3);
    miPila->push(miPila,4);
    miPila->push(miPila,5);

    while( ! miPila->isEmpty(miPila) ){
        printf("%d\n",miPila->peek(miPila));

        miPila->pop(miPila);
    }

    printf("\nEsto es con cola:\n");

    Cola* miColaXD = ColaNueva();

    miColaXD->push(miColaXD,1);
    miColaXD->push(miColaXD,2);
    miColaXD->push(miColaXD,3);
    miColaXD->push(miColaXD,4);
    miColaXD->push(miColaXD,5);

    while( ! miColaXD->isEmpty(miColaXD) ){
        printf("%d\n",miColaXD->peek(miColaXD));

        miColaXD->pop(miColaXD);
    }

    printf("\n Ahora con una lista enlazada\n");

    ListaEnlazada* miLista = ListaEnlazadaNueva();

    for(int a=10; a>=0; a--){
        miLista->insertar(miLista,a,miLista->tam);
    }

    miLista->imprimir(miLista);

    miLista->invertir(miLista);

    printf("Lista invertida:\n");

    miLista->imprimir(miLista);
   
    printf("Se buscaran 5 elementos y 5 indices\n");
    for(int a=0; a<5; a++){
        int numero = rand() % 20;
        int pos = miLista->buscarElemento(miLista,numero);
        if(pos == -1){
            printf("El numero %d no esta en la lista\n",numero);
        }else{
            printf("El numero %d esta en la lista en la posicion %d\n",numero,pos);
        }
    }

    for(int a=0; a<5; a++){
        unsigned int pos = rand()%20;
        int*numero;
        miLista->buscarIndice(miLista,pos,&numero);
        if(numero == NULL){
            printf("El indice %d no esta en la lista\n",pos);
        }else{
            printf("El indice %d de la lista contiene al numero %d\n",pos,*numero);
        }
    }
}