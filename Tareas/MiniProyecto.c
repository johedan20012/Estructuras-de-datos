//Luis Kevin Johedan Ramirez Fuentes 19/03/2020
#include <stdio.h>

void leerCandidatos(char candidatos[][100]);

void leerVotos(int* arrVotosCandidatos,int* totalV,int* vValidos,int* vNulos);

void imprimirGanadorYVotos(char candidatos[][100],int* arrVotosCandidatos,int* totalV,int* vValidos,int* vNulos);

int main(){
    char nombresCandidatos[7][100];
    int votosCandidatos[7];
    int totalVotos = 0,votosValidos = 0,votosNulos = 0;

    for(int i = 0; i <7; i++){
        votosCandidatos[i] =0;
    }

    leerCandidatos(nombresCandidatos);

    leerVotos(votosCandidatos,&totalVotos,&votosValidos,&votosNulos);

    imprimirGanadorYVotos(nombresCandidatos,votosCandidatos,&totalVotos,&votosValidos,&votosNulos);
}

void leerCandidatos(char candidatos[][100]){
    printf("Ingresa los nombres de los 7 candidatos:\n");
    for(int  i = 0; i <7; i++){
        fgets(candidatos[i],sizeof(candidatos[i]),stdin);
    }
}

void leerVotos(int* arrVotosCandidatos,int* totalV,int* vValidos,int* vNulos){
    printf("Ingresa los votos:\n");
    int aux;

    scanf("%d",&aux);
    while(aux != 0){
        (*totalV)++;
        if(aux > 7 || aux < 1){
            (*vNulos)++;
        }else{
            (*vValidos)++;
            (*(arrVotosCandidatos +aux-1))++;
        }
        
        scanf("%d",&aux);
    }
}

void imprimirGanadorYVotos(char candidatos[][100],int* arrVotosCandidatos,int* totalV,int* vValidos,int* vNulos){
    int mayor = 0,ganadores = 0;
    printf("El total de votos es: %d, con %d votos validos y %d votos invalidos.\n",*totalV,*vValidos,*vNulos);

    for(int i = 0; i <7; i++){
        if(*(arrVotosCandidatos+i) > mayor){
            mayor = *(arrVotosCandidatos+i);
            ganadores = 1;
        }else if (*(arrVotosCandidatos+i) == mayor){
            ganadores++;
        }
    }

    if(ganadores > 1){
        printf("Los ganadores son:\n");
    }else{
        printf("El ganador es:\n");
    }

    for(int i = 0; i <7; i++){
        if(*(arrVotosCandidatos+i) == mayor){
            printf("%s",candidatos[i]);
        }
    }
}