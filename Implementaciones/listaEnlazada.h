#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "helper.h"

typedef struct ListaEnlazada ListaEnlazada;
typedef struct NodoListaEnlazada NodoListaEnlazada;

struct NodoListaEnlazada{
    int dato;
    NodoListaEnlazada* nodoSig;
};

struct ListaEnlazada{
    NodoListaEnlazada* cabeza;
    unsigned int tam;

    void (*insertar)(ListaEnlazada*,int,unsigned int);
    void (*eliminarIndice)(ListaEnlazada*,unsigned int);
    void (*eliminarElemento)(ListaEnlazada*,int);
    int (*buscarElemento)(ListaEnlazada*,int);
    void (*buscarIndice)(ListaEnlazada*,unsigned int,int** regreso);
    void (*invertir)(ListaEnlazada*);
    //void (*fusionar)(ListaEnlazada*,ListaEnlazada*); //Preguntar como se realiza el merge

    void (*imprimir)(ListaEnlazada*);
};

ListaEnlazada* ListaEnlazadaNueva();

#endif
