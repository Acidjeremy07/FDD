#include<stdio.h>
#define INF 99999999
 
int voraz(int cambio){
    //int denominacion[]={60,10,5,2,1}; //57 ==> (5)$10 + (1)$5 + (1)$2
    int denominacion[]={6,4,1}; //8
    int sum = 0, contMonedas=0, i, num;
    while(cambio > 0){
        for(i =0; i < 3; i++){
            if (cambio >= denominacion[i]){
                num = cambio/denominacion[i];
                contMonedas += num;
                cambio = cambio%denominacion[i];
                sum += denominacion[i]*num;
            }
        }
    }
    printf("Numero de monedas (algoritmo voraz) = %d\n", contMonedas);
}


int progDinamica(int cambio){
    int tabla[3][9];
    int denominacion[]={1,4,6};
    int i, j, opcion1, opcion2;
    
    for(i =  0; i < 3; i++){
        tabla[i][0] = 0; // caso base
    }

    printf("\n\nTabla de programación dinamica\n");
    for(i = 0; i < 3; i++){
        for(j = 1; j < 9; j++){
            if(i-1 < 0)
                opcion1 = INF; 
            else
                opcion1 = tabla[i-1][j]; // opcion1 = no tomar la denominacion
            opcion2 = 1 + tabla[i][j - denominacion[i]]; // opcion = tomar esa denominacion
            tabla[i][j] = opcion1 < opcion2 ? opcion1 : opcion2; // if - else
            printf(" %d\t", tabla[i][j]);
        }
        printf("\n");
    }
    printf("\nNumero de monedas (programación dinamica)= %d\n", tabla[2][8]);
    return tabla[2][8];
}

//Algoritmos para el problema de devolver el cambio
int main(){
    //int cambio = 12;
    //int tabla[4][13];
    //int denominacion[]={1,2,5,10};
    voraz(8);
    progDinamica(8);
    return 0;
}
