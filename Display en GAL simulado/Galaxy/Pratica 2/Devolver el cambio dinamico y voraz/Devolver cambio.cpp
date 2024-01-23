//Cazares Cruz Jeremy Sajid

#include<stdio.h>
#include<fstream>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<ctime>

#define CLOCKS_PER_MICROSEC 1000000
#define INF 99999999
#define MONT 6
#define ND1 7
#define ND2 4 

using namespace std;

void obtenerD1 (int *Den_D1)
{
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;

	Archivo.open("D1.txt",ios::in);	
	if (Archivo.fail())
	{
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof())
	{					
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<ND1;j++)
		{
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			Den_D1[j]=conv;
		}
	}
	Archivo.close();						
}
void obtenerD2 (int *Den_D2)
{
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;

	Archivo.open("D2.txt",ios::in);		
	if (Archivo.fail())
	{
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof())
	{				
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<ND2;j++){
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			Den_D2[j]=conv;
		}
	}
	Archivo.close();						
}
void obtenerMontos (int *Montos)
{
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;

	Archivo.open("Montos.txt",ios::in);		
	if (Archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof())
	{					
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<MONT;j++)
		{
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
      Montos[j]=conv;
		}
	}
	Archivo.close();						
}
void assignment (int *D1,int *D2,int *Montos)
{
	int i,j,k;
    for(i=0;i<ND1;i++)
	{
      D1[i]=0; 
    }
    for(j=0;j<ND2;j++)
	{
      D2[j]=0;
    }
    for(k=0;k<MONT;k++)
	{
      Montos[k]=0;
    }
}
int voraz(int *MontosDs,int *denominaciones,int tamDs,int tamMont)
{
    int banca=0, suma=0,contador=0,i,numero,j,l;

    for(j=0;j<tamMont;j++)
	{
      cout<<"Para devolver el monto de ["<<MontosDs[j]<<"] se necesitan:"<<endl;
      banca=MontosDs[j];
      while(banca>0)
	  {
            for(i=0;i<tamDs;i++)
			{
              if (banca>=denominaciones[i])
			  {
                  numero=banca/denominaciones[i];
                  contador+=numero;
                  banca=banca%denominaciones[i];
                  suma+=denominaciones[i]*numero;
                  cout<<numero<<" moneda(s)/billete(s) de $"<<denominaciones[i]<<endl;
                }
            }
      }
      cout<<"(Voraz) Total de monedas a devolver=\t"<<contador<<"\n\n";
      contador=0;
    }
    cout<<"\n";
} 
void Dinamica(int *MontosD,int *denominaciones,int tamDs,int tamMont)
{
    int h,i,j,opcion1,opcion2;

    for(h=0;h<tamMont;h++)
	{
      int tabla1[tamDs][MontosD[h]+1],tabla2[tamDs][MontosD[h]+1];
    
        for(i=0;i<tamDs;i++)
		{
            tabla1[i][0]=0; 
            tabla2[i][0]=0;
        }
        for(i=0;i<tamDs;i++)
		{
            for(j=1;j<=MontosD[h];j++)
			{
                if(i-1<0)
				{
                  opcion1= INF; 
                }
                else{
                  opcion1=tabla1[i-1][j];
                }
         	   if(j-denominaciones[i]>=0)
        	    {
         	       opcion2=1+tabla1[i][j-denominaciones[i]]; 
				}
				else
				{
            		opcion2 = INF;
            	}
            	tabla1[i][j]=opcion1<opcion2 ? opcion1 : opcion2; 
            	tabla2[i][j]=opcion1<opcion2 ? 1 : 2;
            }
        }
        cout<<"(Dinamico) Total de monedas a devolver para [$"<<MontosD[h]<<"]\t\tes:\t"<<tabla1[tamDs-1][MontosD[h]]<<endl;
    } 
	cout<<"\n\n"; 
}

void GenerarDiv()
{
  cout<<"****************************************\n\n"<<endl;
}
void autoTest(int *Montos,int *denominacionD1, int *denominacionD2);
void generarMicroSeg(clock_t t, int i)
{
    float tiempo_en_sec=(float(t)/CLOCKS_PER_SEC);
    long tiempo=tiempo_en_sec*CLOCKS_PER_MICROSEC;		
    cout<<"\n"<<i<<".-Duracion del proceso:\t"<<tiempo<<"micro segundos."<<endl;

}

int main()
{
    int *D1,*D2,*Montos;

    D1    =(int*)malloc(ND1*sizeof(int));
    D2    =(int*)malloc(ND2*sizeof(int));
    Montos=(int*)malloc(MONT*sizeof(int));

    assignment(D1,D2,Montos);
    obtenerD1(D1);
    obtenerD2(D2);
    obtenerMontos(Montos);

    autoTest(Montos,D1,D2);

    return 0;
}

void autoTest(int *Montos,int *D1, int *D2)
{
    int i=1;
    clock_t t1,t2,t3,t4;

    t1 =clock();
    voraz(Montos,D1,ND1,MONT);
    t1=clock()-t1;
      generarMicroSeg(t1,i);i++;
      GenerarDiv();

    t2 =clock();
    voraz(Montos,D2,ND2,MONT);
    t2=clock()-t2;
      generarMicroSeg(t2,i);i++;
      GenerarDiv();
      
    t3 =clock();
    Dinamica(Montos,D1,ND1,MONT);
    t3=clock()-t3;
    generarMicroSeg(t3,i);i++;
    GenerarDiv();

    t4 =clock();
    Dinamica(Montos,D2,ND2,MONT);
    t4=clock()-t4;
    generarMicroSeg(t4,i);i++;

}


