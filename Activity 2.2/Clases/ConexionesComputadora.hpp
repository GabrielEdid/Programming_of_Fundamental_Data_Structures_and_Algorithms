// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// ConexionesComputadora.hpp

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp

#include <iostream>
#include "ADT/Stack.hpp"
#include "ADT/LinkedList.hpp"
#include "ADT/Node.hpp"
#include "Registro.hpp"
#include <vector>
using namespace std; 

template <class T>
class ConexionesComputadora {
private:
  string IP = "";
  string Nombre = "";
  Stack <T> * conexionesEntrantes = new Stack<T>();
  vector <T> * conexionesSalientes = new vector<T>();

public:
  ConexionesComputadora() = default;
  ConexionesComputadora(string _ip, string _nombre) : IP(_ip), Nombre(_nombre) {};

  Stack<T> * getConexionesEntrantes();
  vector<T> * getConexionesSalientes();
 
  void llenarConexiones(vector<T>); 

  int totalConexionesEntrantes(); 
  int totalConexionesSalientes(); 
  void ultimaConexion();
  void tresConexionesConsecutivas(vector<T>);
};

template <class T>
void ConexionesComputadora<T>::llenarConexiones(vector<T> registros){
 for (auto a : registros) {
   if (a.getIpOrigen() == IP) {
     conexionesSalientes->push_back(a);
   }
  else if(a.getIpDestino() == IP) {
    conexionesEntrantes->insert_back(a);
  }
 }   
}

template <class T>
Stack <T> * ConexionesComputadora<T>::getConexionesEntrantes(){
  return conexionesEntrantes;
}

template <class T>
vector <T> * ConexionesComputadora<T>::getConexionesSalientes(){
  return conexionesSalientes;
}

template <class T>
int ConexionesComputadora<T>::totalConexionesEntrantes(){
  return conexionesEntrantes -> size();
}

template <class T>
int ConexionesComputadora<T>::totalConexionesSalientes(){
  return conexionesSalientes -> size();
}

template <class T>
void ConexionesComputadora<T>::ultimaConexion(){
  Registro ultima = conexionesEntrantes -> top() -> getInfo();
  cout << "\nLa ultima conexion recibida (Entrante) es: " << ultima << endl;
  string IPDestino = ultima.getIpDestino();
  string IPOrigen = ultima.getIpOrigen();
  string direccionIPDestino;
  string direccionIPOrigen;
  int puntoDest = 0;
  int puntoOr = 0;

  if (IPOrigen != "-"){
    for (int i=0; i < IPDestino.length(); i++){
      direccionIPDestino = direccionIPDestino + IPDestino[i];
      if(IPDestino[i] == '.'){
        puntoDest ++;
        if (puntoDest == 3){
          break;
        }
      }
    }
  }
  for (int i=0; i < IPOrigen.length(); i++){
    direccionIPOrigen = direccionIPOrigen + IPOrigen[i];
    if(IPOrigen[i] == '.'){
      puntoOr ++;
      if (puntoOr == 3){
        break;
      }
    }
  }
  if (direccionIPOrigen == direccionIPDestino){
    cout << "La Ultima Conexion es Interna" << endl;
  }
  else{
    cout << "La Ultima Conexion es Externa" << endl;
  }
}


template <class T>
void ConexionesComputadora<T>::tresConexionesConsecutivas(vector <T> registros){
  int i;
  for(i=0; i < registros.size()-2; i++){
    if(registros[i].getIpOrigen() == IP && registros[i+1].getIpOrigen() == IP && registros[i+2].getIpOrigen() == IP){
      if (registros[i].getPuertoDestino() == "80" && registros[i+1].getPuertoDestino() == "80" && registros[i+2].getPuertoDestino() == "80") {
      cout << "\nSe encontraron tres visitas seguidas a sitios Web por el puerto 80 con el IP: " << IP << endl;
      break;
      }
      else if (registros[i].getPuertoDestino() == "443" && registros[i+1].getPuertoDestino() == "443" && registros[i+2].getPuertoDestino() == "443") {
      cout << "\nSe encontraron tres visitas seguidas a sitios Web por el puerto 443 con el IP: " << IP << endl;
      break;
      }
    }
  }
  if(i == registros.size()-2){
    cout << "\nNo se encontraron tres visitas seguidas iguales por el puerto 80 o 443 con el IP: " << IP << endl; 
  }
}

#endif