// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Vehiculo.cpp


#include "Vehiculo.hpp"

ostream & Vehiculo::print(ostream & os) const{
  os << "Código: " << codigo << endl;
  os << "Marca: " << marca << endl;
  os << "Modelo: " << modelo << endl;
  os << "Año: " << ano << endl;
  os << "Kilometraje: " << kilometraje << endl;
    
    return os;
}

ostream &operator<<(ostream &os, const Vehiculo & coche) {
  return coche.print(os);
}