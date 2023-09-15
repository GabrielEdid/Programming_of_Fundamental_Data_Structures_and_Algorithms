// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Motocicleta.cpp

#include "Motocicleta.hpp"
#include "Vehiculo.hpp"

ostream & Motocicleta::print(ostream & os) const {
  os << "Código: " << codigo << endl;
  os << "Marca: " << marca << endl;
  os << "Modelo: " << modelo << endl;
  os << "Año: " << ano << endl;
  os << "Kilometraje: " << kilometraje << endl;
  os << "Cilindraje: " << cilindraje << endl;
    
    return os;
}

ostream &operator<<(ostream &os, const Motocicleta & coche){

  return coche.print(os);
}