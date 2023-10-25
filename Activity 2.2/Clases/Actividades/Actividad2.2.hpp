// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad2.2.hpp

#ifndef Actividad2_2_hpp
#define Actividad2_2_hpp

#include <iostream>
#include "../Registro.hpp"
#include "../ConexionesComputadora.hpp"
using namespace std;

template <class T>
class Actividad2_2 {
public:
    static int darIpInterna();
    static void pregunta1(string, int);
    static void pregunta2(ConexionesComputadora<T>);
    static void pregunta3(ConexionesComputadora<T>);
    static void pregunta4(ConexionesComputadora<T>);
    static void pregunta5(ConexionesComputadora<T>, vector<T>);

};

template <class T>
int Actividad2_2<T>::darIpInterna()
{
  int ipInterna = 0; 
  while (ipInterna > 150 || ipInterna < 1) {
    cout << "Introduce la IP interna (1-150): ";
    cin >> ipInterna;
    if (ipInterna <= 150 && ipInterna >= 1) {
      break;
    } 
    else {
      cout << "Valor fuera de rango!" << endl;
    }
  }
  return ipInterna;
}

// Pregunta 1 - ¿Qué dirección ip estás usando?
template <class T>
void Actividad2_2<T>::pregunta1(string direccionIP, int ipInterna)
{
  cout << "\nLa dirección IP que se utilizara es: " << direccionIP + to_string(ipInterna) << endl;
}

// Pregunta 2 - ¿Cuál fue la dirección IP de la última conexión que recibió esta computadora? ¿Es interna o externa?
template <class T>
void Actividad2_2<T>::pregunta2(ConexionesComputadora<T> Conexiones)
{
  Conexiones.ultimaConexion();
}

// Pregunta 3 - ¿Cuántas conexiones entrantes tiene esta computadora?
template <class T>
void Actividad2_2<T>::pregunta3(ConexionesComputadora<T> Conexiones)
{
  cout << "\nEl Total de Conexiones Entrantes es: " << Conexiones.totalConexionesEntrantes() << endl;
}

// Pregunta 4 - ¿Cuántas conexiones salientes tiene esta computadora?
template <class T>
void Actividad2_2<T>::pregunta4(ConexionesComputadora<T> Conexiones)
{
  cout << "\nEl Total de Conexiones Salientes es: " << Conexiones.totalConexionesSalientes() << endl;
}

// Pregunta 5 - ¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web?
template <class T>
void Actividad2_2<T>::pregunta5(ConexionesComputadora<T> Conexiones, vector<T> registros)
{
  Conexiones.tresConexionesConsecutivas(registros);
}

#endif /* Actividad2_2_hpp */