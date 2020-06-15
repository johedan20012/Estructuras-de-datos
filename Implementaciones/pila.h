#ifndef PILA_H
#define PILA_H

#include "helper.h"

typedef struct Pila Pila;
typedef struct NodoPila NodoPila;

struct NodoPila{
    int dato;
    NodoPila* nodoSig;
};

struct Pila{
    NodoPila* cima;
    int tam;
    int tamMax;

    Bool (*isEmpty)(Pila*);

    Bool (*isFull)(Pila*);

    void (*push)(Pila*,int);

    void (*pop)(Pila*);

    int (*peek)(Pila*);
};

Pila* PilaNueva();

/*static Bool isEmpty(const Pila* pila);

Bool isFull(Pila* pila);

void push(Pila* pila,int dato);

void pop(Pila* pila);

int peek(Pila* pila);*/

#endif