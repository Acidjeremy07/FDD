//Cazares Cruz Jeremy Sajid
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <iostream>
#define INF 99999999

using namespace std;

int voraz(int cambio, int * den, int tamD)
{
    int banca = cambio, suma = 0, contador=0, i, numero;
    char *mensaje;
    while(banca > 0);
	{
        for(i =0; i < tamD; i++)
		{
            if (banca >= den[i])
			{
                numero = banca/den[i];
                contador += numero;
                banca = banca%den[i];
                suma += den[i]*numero;
                mensaje && numero == 1 ? "moneda" : "monedas";
                cout<<numero<<"de"<<mensaje<<den[i]<<endl;
			} 
		}
	}
    cout<<"Monedas por algoritmo voraz= "<<contador<<endl;
}


void Dinamica(int cambio, int * den, int tamD)
{
    int t[tamD][cambio+1], t2[tamD][cambio+1];
    int i, j, opcion1, opcion2;
	char * mensaje;
    for(i =  0; i < tamD; i++)
	{
        t[i][0] = 0; 
        t2[i][0] = 0;
    }
    for(i = 0; i < tamD; i++)
	{
        for(j = 1; j <= cambio; j++)
		{
            if(i-1 < 0)
            {
                opcion1 = INF; 
            }
            else
            {
                opcion1 = t[i-1][j];
            }
			if(j - den[i] >= 0)
			{
				opcion2 = 1 + t[i][j - den[i]]; 
        	}
            else
            {
            	opcion2 = INF;
            }
            t[i][j] = opcion1 < opcion2 ? opcion1 : opcion2; 
			t2[i][j] = opcion1 < opcion2 ? 1 : 2;
        }
    }
	cout<<"Monedas por algoritmo dinamico=" << t[tamD-1][cambio]<<endl;

}

void Pedir(int * devolver, int ** den, int * tamA)
{
    int des = 0,a;
    (*den) = (int *) malloc(1 * sizeof(int));
    cout<<"Cual es la cantidad que se desea devolver?:"<<endl;
    cin>>a;
    *devolver=a;
    cout<<"Coloque las denominaciones a usar y al final coloque 0 porfavor para saber que termino(todas separadas por un intro)"<<endl;
    do{
        cin>>des;
        if(des != 0)
		{
	 	   if((*tamA) == 0){
    	    }else{
    	        (*den) = (int *) realloc((*den),((*tamA)+1) * sizeof(int));
    	    }
			(*den)[*tamA] = des;
    		(*tamA)++;
    	}
    }while(des != 0);
}

void QuickSort(int *array, int inicio, int final) 
{
	int i = inicio, f = final, tmp;
	int x = array[(inicio + final) / 2];
	do{
    while(array[i] < x && f <= final) 
	{
      i++;
    }while(x < array[f] && f > inicio) 
	{
      f--;
    }
  	  if(i <= f) 
		{
 	     tmp = array[i];
 	     array[i] = array[f];
 	     array[f] = tmp;
 	     i++; f--;
 	   }
	}while(i <= f);

  if(inicio < f) 
  {
    QuickSort(array,inicio,f);
  }

  if(i < final)
  {
    QuickSort(array,i,final);
  }

}

int main()
{
    int cambio, tamD = 0, i;
    int * den, * reves;
    Pedir(&cambio,&den,&tamD);
    QuickSort(den, 0, tamD - 1);
    reves = (int *) malloc(tamD * sizeof(int));
    for(i = 0; i < tamD; i++)
	{
	reves[i] = den[(tamD-1)-i];
	} 
    voraz(cambio,reves,tamD);
    Dinamica(cambio,den,tamD);
    return 0;
}
