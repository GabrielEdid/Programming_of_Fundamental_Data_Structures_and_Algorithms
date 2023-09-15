// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Venta.cpp

#include "Venta.hpp"

ostream &operator<<(ostream &os, const Venta &venta) {
  os << "Monto: $" << venta.monto << endl;
  os << "*** Datos del Vehiculo ***\n" << *venta.vehic;
  os << "*** Datos del Comprador ***\n" << *venta.comp << endl;
  return os;
}

bool Venta::monto_desc(Venta* a, Venta* b) { 
  return a->monto > b->monto; 
}

bool Venta::operator<(const Venta & venta) const {
  return monto < venta.monto;
}