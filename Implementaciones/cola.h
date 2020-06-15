#ifndef COLA_H
#define COLA_H

#include "helper.h"

typedef struct Cola Cola;
typedef struct NodoCola NodoCola;

struct NodoCola{
    int dato;
    NodoCola* nodoSig;
};

struct Cola {
    NodoCola* frente;
    NodoCola* atras;

    int tam;
    int tamMax;

    Bool (*isEmpty)(Cola*);

    Bool (*isFull)(Cola*);

    void (*push)(Cola*,int);

    void (*pop)(Cola*);

    int (*peek)(Cola*);
};

Cola* ColaNueva();

#endif