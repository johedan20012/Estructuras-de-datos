//Luis Kevin Johedan Ramirez Fuentes 19/03/2020
#include <stdio.h>
#include <stdlib.h>

struct Nodo{  //Estructura de un nodo para una lista simple enlazada
    char dato;
    struct Nodo* sigNodo;
};

void meterEnLista(struct Nodo** cabeza, char dato){
    struct Nodo* nodoNuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoNuevo)
    nodoNuevo->dato = dato;
    nodoNuevo->sigNodo = NULL;
    
    if((*cabeza) == NULL){
        (*cabeza) = nodoNuevo;
        return;
    }

    struct Nodo* nodoActual = (*cabeza);
    while( nodoActual->sigNodo != NULL){
        nodoActual = nodoActual->sigNodo;
    }

    nodoActual->sigNodo = nodoNuevo;
}

void imprimirLista(struct Nodo* cabeza){
    if(cabeza == NULL){
        printf("La lista esta vacia\n");
        return;
    }

    struct Nodo* nodoActual = cabeza;
    printf("%c",nodoActual->dato);
    nodoActual = nodoActual->sigNodo;

    while(nodoActual != NULL){
        printf(" - %c",nodoActual->dato);
        nodoActual = nodoActual->sigNodo;
    }
}

int main(){
    printf("Ingresa tu nombre:\n");

    struct Nodo* cabezaLista = NULL;

    int carac;
    carac = getchar();
    while(carac != '\n' && carac != ' ' && carac != EOF){
        meterEnLista(&cabezaLista,carac);
    }

    printf("Se guardo el nombre en una lista, que quedo:\n");
    imprimirLista(cabezaLista);

    return 0;
}
