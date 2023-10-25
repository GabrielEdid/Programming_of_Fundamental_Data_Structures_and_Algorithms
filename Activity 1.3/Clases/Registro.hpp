// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// 21/09/2023
// Registro.hpp

#ifndef Registro_hpp
#define Registro_hpp

#include <iostream>
using namespace std;

class Registro {
public:
    string fecha, hora, ipOrigen, nombreOrigen, ipDestino, nombreDestino, puertoOrigen, puertoDestino;

    Registro(string f, string h, string ipo, string po, string no, string ipd, string pd, string nd):
    fecha(f), hora(h), ipOrigen(ipo), puertoOrigen(po), nombreOrigen(no), ipDestino(ipd), puertoDestino(pd), nombreDestino(nd) {}
    Registro() {}

  string getFecha() const;

  friend ostream & operator<<(ostream & os, const Registro & registro);
    
  static bool compara_fecha_asc(Registro, Registro);

};

#endif /* Registro_hpp */
