#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#define aux '.'
#define SIMBOLO_MINA '*'
//Aqui se pueden modificar los datos de entrada, como el numero de filas y columnas
#define COLUMNAS 7
#define FILAS 7


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

// Colocar minas aleatoriamente en mi tablero
void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < 7; l++) {
    int fila = NumeroAleatorio(0, FILAS - 1);
    int columna = NumeroAleatorio(0, COLUMNAS - 1);
    colocarMina(fila, columna, tablero);
  }
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

int main() {
	int F=0, C=0;
	char tablero[FILAS][COLUMNAS];
	srand(getpid());
	iniciarTablero(tablero);
	colocarMinasAleatoriamente(tablero);
	MostrarTablero(tablero);
	return 0;
}
