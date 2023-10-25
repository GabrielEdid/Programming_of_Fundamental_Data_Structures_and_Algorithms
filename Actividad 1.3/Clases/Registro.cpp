// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// 21/09/2023
// Registro.cpp

#include "Registro.hpp"
#include <iostream>
using namespace std;

string Registro::getFecha() const
{
    return fecha;
}

ostream & operator<<(ostream & os, const Registro & registro)
{
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

bool Registro::compara_fecha_asc(Registro a, Registro b)
{
    return a.fecha < b.fecha;
}