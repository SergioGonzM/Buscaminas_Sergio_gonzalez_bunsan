#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

#define aux '.'
#define SIMBOLO_MINA '*'
#define COLUMNAS 4
#define FILAS 4

//Inicializa mi tablero
void iniciarTablero(char tablero[FILAS][COLUMNAS]) {
  for (int l = 0; l < FILAS; l++) {
    for (int m = 0; m < COLUMNAS; m++) {
      tablero[l][m] = aux;
    }
  }
}

//Generacion de un numero aleatorio
int NumeroAleatorio(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


// Coloca una mina 
void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = SIMBOLO_MINA;
}


// Convertir a char
char Conversion(int numero) {
  return numero + '0';
}

// Numero de Minas que hay cerca de cada posicion en mi tablero
int NMinasCerca(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  int TotalMinas = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;	
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= FILAS) {
    filaFin = FILAS - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNAS) {
    columnaFin = COLUMNAS - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (tablero[m][l] == SIMBOLO_MINA) {
        TotalMinas++;
      }
    }
  }
  return TotalMinas;
}

//Mostrar tablero con los numeros de minas
void MostrarTablero(char tablero[FILAS][COLUMNAS]) {
  for (int l = 0; l < FILAS; l++) {
    for (int m = 0; m < COLUMNAS; m++) {
      char MinasenTablero = aux;
      if (tablero[l][m]) {
        int minasCercanas = NMinasCerca(l, m, tablero);
        MinasenTablero = Conversion(minasCercanas);
      }
      if (tablero[l][m] == SIMBOLO_MINA) {
        MinasenTablero = SIMBOLO_MINA;
      }
      printf("|%c", MinasenTablero);
    }
    printf("\n");
  }
}


int main(int argc, char *argv[]) {

	if (argc==1)
    {
        printf("Debes ingresar mas parametros...\n");
        return 1;
    }
    
    ifstream archivo;
    string texto;
	archivo.open(argv[1],ios::in); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}	
	
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
	char tablero[FILAS][COLUMNAS];
	srand(getpid());
	iniciarTablero(tablero);
	colocarMina(0, 0, tablero);
    colocarMina(2, 1, tablero);
	cout<<endl;
	MostrarTablero(tablero);
	return 0;
}


