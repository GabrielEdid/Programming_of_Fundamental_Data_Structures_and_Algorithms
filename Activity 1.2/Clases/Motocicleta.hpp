// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Motocicleta.hpp

#ifndef Motocicleta_hpp
#define Motocicleta_hpp

#include "Vehiculo.hpp"
#include <iostream>
using namespace std;

class Motocicleta: public Vehiculo {
private:
  string cilindraje;
public:
  //Constructores
  Motocicleta(int cod, string marc, string mod, int num, int km, string cili) : Vehiculo(cod, marc, mod, num, km), cilindraje(cili) {};
  Motocicleta() {};

  friend ostream & operator<<(ostream &, const Motocicleta &);

  virtual ostream & print(ostream &) const;

};

#endif