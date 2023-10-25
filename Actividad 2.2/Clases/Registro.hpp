// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Registro.hpp

#ifndef Registro_hpp
#define Registro_hpp

#include <iostream>
using namespace std;

class Registro {
private:
    string fecha, hora, ipOrigen, nombreOrigen, ipDestino, nombreDestino, puertoOrigen, puertoDestino;
public:
    Registro(string f, string h, string ipo, string po, string no, string ipd, string pd, string nd):
    fecha(f), hora(h), ipOrigen(ipo), puertoOrigen(po), nombreOrigen(no), ipDestino(ipd), puertoDestino(pd), nombreDestino(nd) {}
    Registro() {}

  string getFecha() const;
  string getHora() const;
  string getIpOrigen() const;
  string getPuertoOrigen() const;
  string getNombreOrigen() const;
  string getIpDestino() const;
  string getPuertoDestino() const;
  string getNombreDestino() const;

  friend ostream & operator<<(ostream & os, const Registro & registro);
    
  static bool compara_fecha_asc(Registro, Registro);
    
  bool operator!=(const Registro& other) const;
    
  bool operator==(const Registro& other) const;


};

#endif /* Registro_hpp */
