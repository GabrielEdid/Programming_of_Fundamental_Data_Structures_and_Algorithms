// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Venta.hpp

#ifndef Venta_hpp
#define Venta_hpp

#include "Vehiculo.hpp"
#include "Comprador.hpp"
#include <iostream>
using namespace std;

class Venta {
public:
  int monto;
  Vehiculo* vehic;
  Comprador* comp;
public:
  //Constructores
  Venta() {};
  Venta(int mon, Vehiculo* vehicIn, Comprador* compIn) : monto(mon), vehic(vehicIn), comp(compIn) {};

  friend ostream & operator<<(ostream &, const Venta &);

  static bool monto_desc(Venta*, Venta*); // Corrección aquí

  bool operator<(const Venta & venta) const;

};

#endif