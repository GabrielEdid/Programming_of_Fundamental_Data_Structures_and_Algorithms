// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Vehiculo.hpp

#ifndef Vehiculo_hpp
#define Vehiculo_hpp

#include <iostream>
using namespace std;

class Vehiculo {
public:
  int codigo, ano, kilometraje;
  string marca, modelo;
  //Constructores
  Vehiculo() {};
  Vehiculo(int cod, string marc, string mod, int num, int km) : codigo(cod), marca(marc), modelo(mod), ano(num), kilometraje(km) {};

  friend ostream & operator<<(ostream &, const Vehiculo &);
    
  virtual ostream & print(ostream & ) const;

  
};

#endif