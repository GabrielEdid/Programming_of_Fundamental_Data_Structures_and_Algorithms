// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Camioneta.hpp

#ifndef Camioneta_hpp
#define Camioneta_hpp

#include "Vehiculo.hpp"
#include <iostream>
using namespace std;

class Camioneta: public Vehiculo {
private:
  string traccion;
public:
  //Constructores
  Camioneta(int cod, string marc, string mod, int num, int km, string tracc) : Vehiculo(cod, marc, mod, num, km), traccion(tracc) {};
  Camioneta() {};

  friend ostream & operator<<(ostream &, const Camioneta &);

  virtual ostream & print(ostream &) const;


};

#endif