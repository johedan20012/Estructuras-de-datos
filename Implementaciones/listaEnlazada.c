#include <stdio.h>
#include <stdlib.h>

#include "listaEnlazada.h"

static NodoListaEnlazada* NodoNuevo(int dato){
    NodoListaEnlazada* nuevo = (NodoListaEnlazada*) malloc(sizeof(NodoListaEnlazada));
    nuevo->dato = dato;
    nuevo->nodoSig = NULL;

    return nuevo;
}

static void insertar(ListaEnlazada* lista,int dato,unsigned int pos){
    NodoListaEnlazada* nuevo = NodoNuevo(dato);
    lista->tam += 1;

    if(lista->cabeza == NULL){
        lista->cabeza = nuevo;
        return;
    }else if(pos == 0){
        nuevo->nodoSig = lista->cabeza;
        lista->cabeza = nuevo;
        return;
    }

    NodoListaEnlazada* nodoAct = lista->cabeza;
    while(pos > 0 && nodoAct->nodoSig != NULL){
        pos-= 1;
        nodoAct = nodoAct->nodoSig;
    }

    nuevo->nodoSig = nodoAct->nodoSig;
    nodoAct->nodoSig = nuevo;
}

static void eliminarIndice(ListaEnlazada* lista,unsigned int indice){
    if(lista->tam == 0){
        if(DEBUG) printf("Lista vacia, operacion eliminar rechazada\n");
        return;
    }

    if(indice == 0){
        NodoListaEnlazada* aux = lista->cabeza->nodoSig;
        free(lista->cabeza);
        lista->cabeza = aux;

        lista->tam -= 1;
        return;
    }

    NodoListaEnlazada *nodoAct = lista->cabeza,*nodoAnt = NULL;
    while(indice > 0 && nodoAct != NULL){ 
        indice -= 1;
        nodoAnt = nodoAct;
        nodoAct = nodoAct->nodoSig;
    }

    if(indice > 0 || nodoAct == NULL){
        if(DEBUG) printf("Indice fuera de la lista, operacion eliminar rechazada\n");
        return;
    }

    nodoAnt->nodoSig = nodoAct->nodoSig;
    free(nodoAct);
    lista->tam -= 1;
}

static void eliminarElemento(ListaEnlazada* lista,int elemento){
    if(lista->tam == 0){
        if(DEBUG) printf("Lista vacia, operacion eliminar rechazada\n");
        return;
    }

    if(lista->cabeza->dato == elemento){
        NodoListaEnlazada* aux = lista->cabeza->nodoSig;
        free(lista->cabeza);
        lista->cabeza = aux;

        lista->tam -= 1;
        return;
    }

    NodoListaEnlazada *nodoAct = lista->cabeza,*nodoAnt = NULL;
    while( !(nodoAct->dato == elemento) && nodoAct != NULL){
        nodoAnt = nodoAct;
        nodoAct = nodoAct->nodoSig;
    }

    if( !(nodoAct->dato == elemento) || nodoAct == NULL){
        if(DEBUG) printf("Elemento fuera de la lista, operacion eliminar rechazada\n");
        return;
    }

    nodoAnt->nodoSig = nodoAct->nodoSig;
    free(nodoAct);
    lista->tam -= 1;
}

static int buscarElemento(ListaEnlazada* lista,int elemento){
    int pos = 0;
    NodoListaEnlazada* nodoAct = lista->cabeza;
    while(nodoAct!= NULL){
        if(nodoAct->dato == elemento){
            return pos;
        }
        pos++;
        nodoAct = nodoAct->nodoSig;
    }
    if(DEBUG) printf("Elemento %d no encontrado en la lista",elemento);
    return -1;
}

static void buscarIndice(ListaEnlazada* lista,unsigned int indice,int** regreso){
    NodoListaEnlazada* nodoAct = lista->cabeza;
    while(nodoAct!= NULL){
        if(indice == 0){
            *regreso = (int *) malloc(sizeof(int));
            *(*regreso) = nodoAct->dato;
            return;
        }
        indice--;
        nodoAct = nodoAct->nodoSig;
    }
    if(DEBUG) printf("Indice %d fuera de los limites de la lista",indice);
    *regreso = NULL;
    return;
}

static void invertir(ListaEnlazada* lista){
    if(lista->tam == 0){
        if(DEBUG) printf("Lista vacia, operacion invertir rechazada\n");
        return;
    }

    NodoListaEnlazada* Nodo1 = lista->cabeza,*Nodo2 = lista->cabeza->nodoSig,*Nodo3 = NULL;
    lista->cabeza->nodoSig = NULL;
    while(Nodo2 != NULL){
        Nodo3 = Nodo2->nodoSig;
        Nodo2->nodoSig = Nodo1;
        Nodo1 = Nodo2;
        Nodo2 = Nodo3;
    }

    lista->cabeza = Nodo1;
}

static void imprimir(ListaEnlazada* lista){
    NodoListaEnlazada* nodoAct = lista->cabeza;
    while(nodoAct!=NULL){
        printf("%d ",nodoAct->dato);
        nodoAct = nodoAct->nodoSig;
    }
    printf("\n");
}

ListaEnlazada* ListaEnlazadaNueva(){
    ListaEnlazada* nueva = (ListaEnlazada*) malloc(sizeof(ListaEnlazada));
    nueva->cabeza = NULL;
    nueva->tam  = 0;

    nueva->insertar = insertar;
    nueva->eliminarIndice = eliminarIndice;
    nueva->eliminarElemento = eliminarElemento;
    nueva->buscarElemento = buscarElemento;
    nueva->buscarIndice = buscarIndice;
    nueva->invertir = invertir;

    nueva->imprimir = imprimir;
}