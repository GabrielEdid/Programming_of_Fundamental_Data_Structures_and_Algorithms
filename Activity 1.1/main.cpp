/* 
Gabriel Edid Harari A01782146
24 de Agosto del 2023
Actividad 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
*/


#include <iostream>
using namespace std;

unsigned long int sumaIterativa(int n) { // 1 +
  int resultado = 0; // 1 +
  for (int i = 1; i <= n; i++) { // 1 + 1*n + 1*n
    resultado += i; // 2*n
  }
  return resultado; // 1 +
};

/* Análisis de Complejidad - sumaIterativa
    T(n)=1+1+1+1*n+1*n+2*n+1
    T(n)=4+4*n
    T(n)=O(n) complejidad lineal

    Esta función realiza 3 operaciónes cada vez que itera: evalua la igualadad, el incremento de i y la suma del resultado con i. Esta función iterará n veces y repetira estas operaciónes cada vez guardando los datos en un lugar diferente en la memoría cada vez. Es por esto que la función tiene una complejidad de T(n) = O(n), es decir que la función crecera de forma lineal con respecto al tamaño de n.
*/

unsigned long int sumaRecursiva(int n) { // 1 +
  int resultado = 0; // 1 +
  if (n == 0) { // n +
    return 0; // 1 +
  } else { 
    resultado = n + sumaRecursiva(n - 1); // 1 + (n - 1) +
    return resultado; // 1 +
  }
};

/* Análisis de Complejidad - sumaRecursiva
    T(n)=1+1+n+1+1+(n-1)+1
    T(n)=2n+4
    T(n)=O(n) complejidad lineal

    Esta función hace dos operaciónes cada vez que es invocada: la suma y evalua la igualdad. Cada vez que se llama la función de forma iterativa, el valor que se le dará será n-1 y la recursividad no se detendrá hasta que no se llegue a la condición que la detiene (n=0). Es por esto que la función se repetira N veces y repetira en cada iteración las dos operaciónes que se especificaron. Sin embargo, la complejidad espacial sería constante ya que en ningún momento guarda las operaciones en la memoria si no que hasta llegar a la condición de parada. La complejidad de esta función sería de T(n) = O(n), es decir que el tiempo de ejecución de la función crecera de forma lineal con respecto al tamaño de n.
*/

unsigned long int sumaDirecta(int n) { // 1 +
  return (n * (n + 1)) / 2; // 1 + 1 + 1 + 1 
};

/* Análisis de Complejidad - sumaDirecta
    T(n)=1+1+1+1+1
    T(n)=5
    T(n)=O(1) compeljidad constante

    Debido a que no importa el tamaño de N, esta función siempre obtendrá el resultado de forma directa y el tiempo será constante. Esta operación tiene 3 operaciónes y no más. Es por esto que la complejidad de esta función es de T(n) = O(1), es decir que la función no crecerá y será es constante.
*/

int main() {
  const int casos = 4;
  int n[casos]{5,20,70,100}; // Array para los 4 casos de prueba
  for (int i=0; i < casos; i++){
    cout << "Caso de Prueba con N = " << n[i] << endl;
    cout << "Con el Método Iterativo la suma es: " << sumaIterativa(n[i]) << endl;
    cout << "Con el Método Recursivo la suma es " << sumaRecursiva(n[i]) << endl;
    cout << "Con el Método Directo la suma es: " << sumaDirecta(n[i]) << endl; 
    cout << "" << endl;
  }
};