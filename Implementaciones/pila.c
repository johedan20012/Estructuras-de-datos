#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

static NodoPila* NodoNuevo(int dato){
    NodoPila* nuevo = (NodoPila*) malloc(sizeof(NodoPila));
    nuevo->dato = dato;
    nuevo->nodoSig = NULL;

    return nuevo;
}

static Bool isEmpty(Pila* pila){
    if(pila->tam) return false;
    return true;
}

static Bool isFull(Pila* pila){
    if(pila->tam == pila->tamMax) return true;
    return false;
}

static void push(Pila* pila,int dato){
    if(isFull(pila)){ 
        if(DEBUG) printf("Pila llena operacion push rechazada \n");
        return;
    }
    NodoPila* nuevo = NodoNuevo(dato);
    nuevo->nodoSig = pila->cima;
    pila->cima = nuevo;
    pila->tam += 1;
}

static void pop(Pila* pila){
    if(isEmpty(pila)){
        if(DEBUG) printf("Pila vacia operacion pop rechazada \n");
        return;
    }
    NodoPila* aux = pila->cima;
    pila->cima = pila->cima->nodoSig;
    pila->tam -= 1;
    free(aux);
}

static int peek(Pila* pila){
    if(isEmpty(pila)){
        if(DEBUG) printf("Pila vacia operacion peek rechazada \n");
        return -1;
    }
    return pila->cima->dato;
}

Pila* PilaNueva(){
    Pila* nuevo = (Pila*) malloc(sizeof(Pila));
    nuevo->cima = NULL;
    nuevo->tamMax = -1;
    nuevo->tam = 0;
    nuevo->isEmpty = isEmpty;
    nuevo->isFull = isFull;
    nuevo->peek = peek;
    nuevo->pop = pop;
    nuevo->push = push;

    return nuevo;
}