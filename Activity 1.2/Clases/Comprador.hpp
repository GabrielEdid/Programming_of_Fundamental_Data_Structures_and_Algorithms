// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Comprador.hpp


#ifndef Comprador_hpp
#define Comprador_hpp

#include <iostream>
using namespace std;

class Comprador {
public:
  string nombre, apellido;
  int INE;
  //Constructores
  Comprador(int ine, string nom, string ape) : nombre(nom), apellido(ape), INE(ine) {};

  friend ostream & operator<<(ostream &, const Comprador &);

};

#endif