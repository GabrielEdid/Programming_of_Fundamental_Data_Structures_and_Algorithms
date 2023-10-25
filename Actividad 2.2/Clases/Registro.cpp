// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Registro.cpp

#include "Registro.hpp"
#include <iostream>
using namespace std;

string Registro::getFecha() const { return fecha; }

string Registro::getHora() const { return hora; }

string Registro::getIpOrigen() const { return ipOrigen; }

string Registro::getPuertoOrigen() const { return puertoOrigen; }

string Registro::getNombreOrigen() const { return nombreOrigen; }

string Registro::getIpDestino() const { return ipDestino; }

string Registro::getPuertoDestino() const { return puertoDestino; }

string Registro::getNombreDestino() const { return nombreDestino; }

ostream &operator<<(ostream &os, const Registro &registro) {
  os << registro.fecha << " - ";
  os << registro.hora << " - ";
  os << registro.ipOrigen << " - ";
  os << registro.puertoOrigen << " - ";
  os << registro.nombreOrigen << " - ";
  os << registro.ipDestino << " - ";
  os << registro.puertoDestino << " - ";
  os << registro.nombreDestino;
  os << std::endl;

  return os;
}

bool Registro::compara_fecha_asc(Registro a, Registro b) {
  return a.fecha < b.fecha;
}

bool Registro::operator!=(const Registro &other) const {
  return this->ipOrigen != other.ipOrigen || this->ipDestino != other.ipDestino;
}

bool Registro::operator==(const Registro &other) const {

  return this->ipOrigen == other.ipOrigen || this->ipDestino == other.ipDestino;
}