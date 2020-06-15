#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

static NodoCola* NodoNuevo(int dato){
    NodoCola* nuevo = (NodoCola*) malloc(sizeof(NodoCola));
    nuevo->dato = dato;
    nuevo->nodoSig = NULL;

    return nuevo;
}

static Bool isEmpty(Cola* cola){
    if(cola->tam) return false;
    return true;
}

static Bool isFull(Cola* cola){
    if(cola->tam == cola->tamMax) return true;
    return false;
}

static void push(Cola* cola,int dato){
    if(cola->isFull(cola)){ 
        if(DEBUG) printf("cola llena operacion push rechazada \n");
        return;
    }
    NodoCola* nuevo = NodoNuevo(dato);
    nuevo->nodoSig = NULL;
    
    if(cola->frente == NULL) cola->frente = nuevo;

    if(cola->atras == NULL){
        cola->atras = nuevo;
    }else{
        cola->atras->nodoSig = nuevo;
        cola->atras = nuevo;
    }

    cola->tam += 1;
}

static void pop(Cola* cola){
    if(cola->isEmpty(cola)){
        if(DEBUG) printf("Cola vacia operacion pop rechazada \n");
        return;
    }
    NodoCola* aux = cola->frente;
    cola->frente = cola->frente->nodoSig;
    cola->tam -= 1;
    free(aux);
}

static int peek(Cola* cola){
    if(cola->isEmpty(cola)){
        if(DEBUG) printf("Cola vacia operacion peek rechazada \n");
        return -1;
    }
    return cola->frente->dato;
}

Cola* ColaNueva(){
    Cola* nuevo = (Cola*) malloc(sizeof(Cola));
    nuevo->frente = NULL;
    nuevo->atras = NULL;
    nuevo->tamMax = -1;
    nuevo->tam = 0;
    nuevo->isEmpty = isEmpty;
    nuevo->isFull = isFull;
    nuevo->peek = peek;
    nuevo->pop = pop;
    nuevo->push = push;

    return nuevo;
}