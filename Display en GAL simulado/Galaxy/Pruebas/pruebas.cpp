//Cazares Cruz Jeremy Sajid

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
#include <sys/time.h>

using namespace std;

void recuperardenominacion()
{
	ifstream archivo_denominaciones("denominaciones.txt");
	stringstream buffer;
	buffer << archivo_denominaciones.rdbuf();
    contenido_archivo = buffer.str();
    
}

int main()
{
	int i,j,k;
	
	recuperardenominacion();
}
