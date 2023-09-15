// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// Camioneta.cpp

#include "Camioneta.hpp"
#include "Vehiculo.hpp"

std::ostream & Camioneta::print(ostream & os) const{
  os << "Código: " << codigo << endl;
  os << "Marca: " << marca << endl;
  os << "Modelo: " << modelo << endl;
  os << "Año: " << ano << endl;
  os << "Kilometraje: " << kilometraje << endl;
  os << "Tracción: " << traccion << endl;
    
    return os;
}

ostream &operator<<(ostream &os, const Camioneta &coche) {
  return coche.print(os);

}
