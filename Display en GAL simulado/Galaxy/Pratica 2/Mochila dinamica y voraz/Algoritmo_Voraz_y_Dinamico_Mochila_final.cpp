//JESUS ALVAREZ AGUILAR

#include<stdio.h>
#include<fstream>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>

#define MIN 2
#define N 5

using namespace std;

struct ITEM{
	int peso;
	int valor;
	float r_vp;
}obj_de_mochila[N];

/*Declaracion de funciones del algoritmo Voraz*/
void voraz (int capacidad, float *vpMax, float [N]);
void obtenerWeight_voraz (int*pesos_voraz);
void obtenerValue_voraz (int*valores_voraz);
void assignment (int*pesos_voraz,int *valores_voraz);
void obtenerRelacionVW (int*pesos_voraz,int *valores_voraz);
void assignVP (float *vp_Max);
void ordenar_R_VP (float *vp_max);
/*********************************************/
/*Declaracion de funciones del algoritmo Dinamico*/
void progDinamicaMochila(int capacidad, int *pesos_dim, int *valores_dim);
void obtenerWeight_dim (int *pesos_dim);
void obtenerValue_dim (int *valores_dim);
/*********************************************/

int main(){
	setlocale(LC_ALL, "spanish");

	/*Declaracion de variables*/
    int *pesos_voraz, *valores_voraz;
    float *vpMax, mochila[N]={0,0,0,0,0};
    
    pesos_voraz	=(int*) malloc(N* sizeof(int));
    valores_voraz	=(int*) malloc(N* sizeof(int));
    vpMax  =(float*) malloc(N* sizeof(float));

	int *pesos_dim, *valores_dim;
	    
    pesos_dim	=(int*) malloc(N* sizeof(int));
    valores_dim	=(int*) malloc(N* sizeof(int));
	/*********************************************/
    /*Ejecucion del algoritmo Voraz*/

	//n=5 y W=100
	//valores w:	10	20	30	40	50
	//valores v:	20	30	66	40	60

	obtenerWeight_voraz(pesos_voraz);
	obtenerValue_voraz(valores_voraz);
	assignment(pesos_voraz,valores_voraz);
	obtenerRelacionVW(pesos_voraz,valores_voraz);
	assignVP (vpMax);
	ordenar_R_VP (vpMax);
	
	voraz(100, vpMax, mochila);
	/*********************************************/
	/*Ejecucion del algoritmo Dinamico*/

	//n=5 y W=11
	//valores w:	01	02	05	06	07
	//valores v:	01	06	18	22	28

	obtenerWeight_dim(pesos_dim);
	obtenerValue_dim(valores_dim);
	progDinamicaMochila(11,pesos_dim,valores_dim);
}
 
void voraz(int capacidad,float *vpMax, float res[N]){
	int i,j,suma_peso=0,suma_valor=0,suma_peso_aux=0,restante=0,peso_aux=0,valor_aux=0;
	float frac_aux=0,fraccion=0, suma_final_peso, suma_final_valor,peso_fraccionario,valor_fraccionario;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(vpMax[i]==obj_de_mochila[j].r_vp){ 
				suma_peso_aux+=obj_de_mochila[j].peso;
				if(suma_peso_aux<=capacidad){
					suma_peso+=obj_de_mochila[j].peso;
					suma_valor+=obj_de_mochila[j].valor;
					res[j]=1;
	
				}
				else{
					peso_aux=obj_de_mochila[j].peso;
					restante=capacidad - suma_peso;
					fraccion=((float)restante*1)/(float)peso_aux;
					res[j]=fraccion;

					valor_aux=obj_de_mochila[j].valor;

					peso_fraccionario	= peso_aux*fraccion;
					valor_fraccionario	= valor_aux*fraccion;

					suma_final_peso	=(float)suma_peso	+	peso_fraccionario;
					suma_final_valor=(float)suma_valor	+	valor_fraccionario;

					i=N;
				}
			}
		}
	}

	for(int l=0;l<N;l++){
		cout<<"(Voraz) Objetos que van dentro de la mochila["<<l+1<<"]\t=\t"<<res[l]<<endl;
	}
	cout<<"(Voraz) Peso total:\t\t"<<suma_final_peso<<endl;
	cout<<"(Voraz) Valor total:\t"<<suma_final_valor<<"\n\n"<<endl;
}

void obtenerWeight_voraz (int *pesos_voraz){
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;

	Archivo.open("pesos.txt",ios::in);		//Abrimos el archivo en modo lectura.
	if (Archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof()){					//Mientras el cursor no llegue al final seguira leyendo y mostrando el archivo: funcion eof.
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<N;j++){
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			pesos_voraz[j]=conv;
		}
	}
	Archivo.close();						//Cerramos el archivo.
}

void obtenerValue_voraz (int*valores_voraz){
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;

	Archivo.open("valores.txt",ios::in);	//Abrimos el archivo en modo lectura.
	if (Archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof()){					//Mientras el cursor no llegue al final seguira leyendo y mostrando el archivo: funcion eof.
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<N;j++){
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			valores_voraz[j]=conv;
		}
	}
	Archivo.close();						//Cerramos el archivo.
}

void assignment (int*pesos_voraz,int *valores_voraz){
	int i;
	for(i=0;i<N;i++){
		obj_de_mochila[i].peso	=pesos_voraz[i];
		obj_de_mochila[i].valor	=valores_voraz[i];
	}
}

void obtenerRelacionVW (int*pesos_voraz,int *valores_voraz){
	int i;
	float relacion,v,p;
	for(i=0;i<N;i++){
		v=obj_de_mochila[i].valor;
		p=obj_de_mochila[i].peso;
		relacion = v/p; 
		obj_de_mochila[i].r_vp= relacion;	
	}
}

void assignVP (float *vp_max){
	int i;
	float aux_f;
	for(i=0;i<N;i++){
		aux_f=obj_de_mochila[i].r_vp;
		vp_max[i]=aux_f;
	}
}

void ordenar_R_VP (float *vp_max){	
	int i,j,elem;
	float temp;
	
	cout<<"\n";
	for (i=1;i<N;i++){
		for (j=0;j<N-i;j++){
			if (vp_max[j]<vp_max[j+1]){ 	// Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temp = vp_max[j]; 
			vp_max[j] = vp_max[j+1]; 
			vp_max[j+1] = temp;
			}
		}
	}
}

/*Empiezan los modulos del algoritmo Dinamico*/

void progDinamicaMochila(int capacidad, int *pesos_dim, int *valores_dim){
    int tabla[N][capacidad+1];
	int tablaRes[N*capacidad+1][N];
	int sol_parciales[N];
    int i,j;
	
	for(i=0;i<N;i++){
		tabla[i][0]=0;
	}
	cout<<"\t"; 
	for(i=1;i<capacidad+1;i++){
		tabla[0][i]=valores_dim[0];
		cout<<tabla[0][i]<<"\t";
	}
	cout<<"\n";
	for(i=1; i<N; i++){
		cout<<"\t";
		for(j=1;j<capacidad+1;j++){
			if(j < pesos_dim[i]){
				tabla[i][j] = tabla[i-1][j];
				cout<<tabla[i][j]<<"\t";
			}
			else{
				tabla[i][j] = max(tabla[i-1][j], valores_dim[i] + tabla[i-1][j-pesos_dim[i]]);
				cout<<tabla[i][j]<<"\t";
			}
		}
		cout<<"\n";
	}
	cout<<"\n";
	i=N-1;
	j=capacidad;
	while(i>0&&j>0){
		if (j>=pesos_dim[i] && tabla[i][j]==valores_dim[i]+tabla[i-1][j-pesos_dim[i]]){
			cout<<"(Dinamico) Objetos que iran detro de la mochila:\t["<<i+1<<"]"<<endl;
			j -= pesos_dim[i];
		}		
		i--;
	}
	cout<<"(Dinamico) Valor total:\t"<<tabla[N-1][capacidad];

	/*Empiezan la tabla auxiliar de valores-solucion*/
}

void obtenerWeight_dim (int *pesos_dim){
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;
	//int p[N];
	Archivo.open("pesos_dim.txt",ios::in);	//Abrimos el archivo en modo lectura.
	if (Archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof()){					//Mientras el cursor no llegue al final seguira leyendo y mostrando el archivo: funcion eof.
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<N;j++){
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			pesos_dim[j]=conv;
		}
	}
	Archivo.close();						//Cerramos el archivo.
}

void obtenerValue_dim (int *valores_dim){
	ifstream Archivo;
	string texto, str_aux;
	int tam_linea,i,j,conv;
	Archivo.open("valores_dim.txt",ios::in);//Abrimos el archivo en modo lectura.
	if (Archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	while (!Archivo.eof()){					//Mientras el cursor no llegue al final seguira leyendo y mostrando el archivo: funcion eof.
		getline(Archivo,texto);
		stringstream flujo(texto);
		
		for(j=0;j<N;j++){
			getline(flujo,str_aux,',');
			conv=stoi(str_aux);
			valores_dim[j]=conv;
		}
	}
	Archivo.close();						//Cerramos el archivo.
}

