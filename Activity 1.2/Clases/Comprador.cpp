// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Comprador.cpp

#include "Comprador.hpp"

ostream &operator<<(ostream &os, const Comprador &comprador) {
  os << "INE: " << comprador.INE << endl;
  os << "Nombre: " << comprador.nombre << endl;
  os << "Apellido: " << comprador.apellido << endl;

  return os;
}
