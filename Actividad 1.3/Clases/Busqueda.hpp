//
//  Busqueda.hpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells Nonell on 10/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
// Moficado por Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355

#ifndef Busqueda_hpp
#define Busqueda_hpp

#include <iostream>
#include <vector>
#include <set>

template <class T>
class Busqueda {
public:
    static int busquedaSecuencialNombreOr(std::vector<T>, const std::string);

    static int busquedaSecuencialCorreo(std::vector<T>, const std::string);

    static std::set <std::string> busquedaSecuencialPuertos(std::vector<T>, const int);

    static int busquedaBinaria(std::vector<T>, T);
    static int busquedaBinaria(std::vector<T>, T, int, int);
};

template <class T>
int Busqueda<T>::busquedaSecuencialNombreOr(std::vector<T> e, const std::string valor)
{
    int i = 0;
    int encontrado = 0;
    
    long int size = e.size();
    
    while (i < size) {
        if (e[i].nombreOrigen == valor) {
            encontrado++;
        }
        ++i;
    }
    
    return encontrado;
}

template <class T>
int Busqueda<T>::busquedaSecuencialCorreo(std::vector<T> e, const std::string valor)
{
    int i = 0;
    int encontrado = 0;
    
    long int size = e.size();
    
    while (i < size) {
        if (e[i].nombreDestino == valor) {
            encontrado++;
        }
        ++i;
    }
    
    return encontrado;
}

template <class T>
std::set <std::string> Busqueda<T>::busquedaSecuencialPuertos(std::vector<T> e, const int valor)
{
    int i = 0;
    std::set <std::string> encontrado;
    
    long int size = e.size();
    
    while (i < size) {
        if (e[i].puertoDestino != "-" && std::stoi(e[i].puertoDestino) <= valor) {
            encontrado.insert(e[i].puertoDestino);
        }
        ++i;
    }
    return encontrado;
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
