//
//  Busqueda.hpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells Nonell on 10/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//
//  Modificado por Gabriel Edid

#ifndef Busqueda_hpp
#define Busqueda_hpp
#include "Comprador.hpp"
#include "Vehiculo.hpp"

#include <iostream>
#include <vector>

template <class T>
class Busqueda {
public:
    static std::vector<T*> busquedaSecuencialNombre(const std::vector<T*>&, const std::string&);

    static std::vector<T*> busquedaSecuencialAnoKilom(const std::vector<T*>&, const int&, const int&);

    static int busquedaBinaria(std::vector<T>, T);
    static int busquedaBinaria(std::vector<T>, T, int, int);
};

template <class T>
std::vector<T*> Busqueda<T>::busquedaSecuencialNombre(const std::vector<T*>& ventas, const std::string& nombreBuscar)
{
    std::vector<T*> resultados;

    for (T* venta : ventas) {
        Comprador* comprador = venta->comp;

        if (comprador && comprador->nombre == nombreBuscar) {
            resultados.push_back(venta);
        }
    }
  return resultados;
}

template <class T>
std::vector<T*> Busqueda<T>::busquedaSecuencialAnoKilom(const std::vector<T*>& ventas, const int& anoBuscar, const int& kilomBuscar)
{
    std::vector<T*> resultados;

    for (T* venta : ventas) {
        Vehiculo* vehiculo = venta->vehic;

        if (vehiculo && vehiculo->ano == anoBuscar && vehiculo->kilometraje <= kilomBuscar) {
            resultados.push_back(venta);
        }
    }

    return resultados;
}

template <class T>
int Busqueda<T>::busquedaBinaria(std::vector<T> e, T valor)
{
   int size = (int) e.size() - 1;
    
    return busquedaBinaria(e, valor, 0, size);
}


template <class T>
int Busqueda<T>::busquedaBinaria(std::vector<T> e, T valor, int inferior, int superior)
{
    if (inferior >= superior)
    {
        return -1;
    }
    else  {
        int mitad = (inferior + superior) / 2;
        
        if (e[mitad] == valor) {
            return mitad;
        }
        else if (valor < e[mitad])
            return busquedaBinaria(e, valor, inferior, mitad);
        else
            return busquedaBinaria(e, valor, mitad + 1, superior);
    }
}

#endif /* Busqueda_hpp */
