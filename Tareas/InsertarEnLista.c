//Luis Kevin Johedan Ramirez Fuentes 19/03/2020
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uInt;

struct Nodo{  //Estructura de un nodo para una lista simple enlazada
    char dato;
    struct Nodo* sigNodo;
};

void Insertar(struct Nodo** cabeza, char dato,uInt posicion){
    struct Nodo* nodoNuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoNuevo == NULL) return;
    
    nodoNuevo->dato = dato;
    
    if((*cabeza) == NULL  || posicion == 0){
        nodoNuevo->sigNodo = (*cabeza);
        (*cabeza) = nodoNuevo;
        return;
    }

    uInt posAct = 1;
    struct Nodo* nodoActual = (*cabeza);
    while( nodoActual->sigNodo != NULL && posAct < posicion){
        nodoActual = nodoActual->sigNodo;
        posAct ++;
    }

    nodoNuevo->sigNodo = nodoActual->sigNodo;
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
    printf("\n");
}

int main(){
    //Comandos
    /*"
        1 {c} {p}  #Mete el caracter "c" en la lista en la posicion "p", si la posicion es mayor que el maximo indice de la lista, el caracter se mete al final de la lista
        2          #Imprime la lista
        3          #Imprime la direccion de la cabeza
    */
   struct Nodo* cabezaLista = NULL;
    while(1){
        char comando;
        scanf("%c",&comando);
        

        if(comando == '1'){
            char caracter;
            uInt pos;
            getchar();
            scanf("%c",&caracter);
            getchar();
            scanf("%u",&pos);

            Insertar(&cabezaLista,caracter,pos);
        }else if(comando == '2'){
            imprimirLista(cabezaLista);
        }else if(comando == '3'){
            printf("Posicion de la cabeza: %d\n",cabezaLista);
        }
    }

    return 0;
}
