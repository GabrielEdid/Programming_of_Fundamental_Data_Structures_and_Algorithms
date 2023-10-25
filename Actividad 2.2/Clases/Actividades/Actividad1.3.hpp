// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad1.3.hpp

#ifndef Actividad1_3_hpp
#define Actividad1_3_hpp

#include <iostream>
#include <vector>
#include <set>
#include "../Registro.hpp"
#include "../Algoritmos/Busqueda.hpp"
#include "../Algoritmos/Ordenamiento.hpp"
using namespace std;

template <class T>
class Actividad1_3 {
public:
    static void pregunta1(vector<T>);
    static void pregunta2(vector<T>);
    static void pregunta3(vector<T>);
    static string pregunta4(vector<T>);
    static void pregunta5(vector<T>);
    static void pregunta6(vector<T>);
    static void pregunta7(vector<T>);

};

// Pregunta 1 - ¿Cuantos Registros Hay?
template <class T>
void Actividad1_3<T>::pregunta1(vector<T> registros)
{
  cout << "\nEl total de registros dentro del archivo es de: " << registros.size() << endl;
}

// Pregunta 2 - ¿Cuántos records hay el segundo día registrado? ¿Que día es ese? 
template <class T>
void Actividad1_3<T>::pregunta2(vector<T> registros)
{
   registros = Ordenamiento<Registro>::insercion(registros, &Registro::compara_fecha_asc);

  cout << "\nVector Ordenado" << endl;
  // Después implementamos método de búsqueda
  string fechaBusca = registros[0].getFecha();

  //Para encontrar el segundo día
  int i = 1;
  for (; fechaBusca == registros[i].getFecha(); ++i);

  fechaBusca = registros[i].getFecha();

  cout << "Segundo día: " << fechaBusca << endl;

  //Para hacer el conteo de elementos en el segundo día
  int cont = 0;
  for (; fechaBusca == registros[i].getFecha(); ++i) {
    cont++;}

  cout << "Registros en Segundo día: " << cont << endl;
    
}

// Pregunta 3 - ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?
template <class T>
void Actividad1_3<T>::pregunta3(vector<T> registros)
{
  cout << endl;
  vector<string> nombresBuscar{"jeffrey", "betty", "katherine", "scott", "benjamin", "samuel", "raymond"};
  
  for(auto a: nombresBuscar){
    int buscar = Busqueda<Registro>::busquedaSecuencialNombreOr(registros, a + ".reto.com");
    cout << "El numero de registros encontrados para " << a << " es de: " << buscar << endl; }
    
}

// Pregunta 4 - ¿Cuál es la dirección de la red interna de la compañía?
template <class T>
string Actividad1_3<T>::pregunta4(vector<T> registros)
{
  int punto=0;
  string direccionIP="";
  string registroIP; 
  int in = 0; 
  for (auto a:registros){
    if (registros[in].getIpOrigen() != "-") {
      registroIP = registros[in].getIpOrigen();
    }
    in ++; 
  }
  for (int i=0; i < registroIP.length(); i++){
    direccionIP = direccionIP + registroIP[i];
    if(registroIP[i] == '.'){
      punto ++;
      if (punto == 3){
        break;
      }
    }
  }
  cout << "\nLa direccion IP de la red es: " << direccionIP << "000" << endl;  
  return direccionIP;
}

// Pregunta 5 - ¿Alguna computadora se llama server.reto.com? 
template <class T>
void Actividad1_3<T>::pregunta5(vector<T> registros)
{
  string server = "server.reto.com";
  int serverEncontrado = Busqueda<Registro>::busquedaSecuencialNombreOr(registros, server);
  cout << "\nSe encontraron " << serverEncontrado << " registros con el nombre " << server << endl;
}

// Pregunta 6 - ¿Qué servicio de correo electrónico utilizan? 
template <class T>
void Actividad1_3<T>::pregunta6(vector<T> registros)
{
  cout << endl;
  vector <string> correos {"google.com","hotmail.com", "outlook.com", "protonmail.com", "freemailserver.com", "mail.yahoo.com" };
  for (auto a:correos){
  int correoEcontrado = Busqueda<Registro>::busquedaSecuencialCorreo(registros, a);
  cout << "Se encontraron " << correoEcontrado << " registros con el correo " << a << endl;
    }
}

// Pregunta 7 - Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando?
template <class T>
void Actividad1_3<T>::pregunta7(vector<T> registros)
{
  cout << "\nPuertos menores a 1000" << endl;
  set <string> puertosEncontrados = Busqueda<Registro>::busquedaSecuencialPuertos(registros, 1000);
  //cout << "Se encontraron " << correoEcontrado << " registros con el correo " << a << endl;
  for (auto a:puertosEncontrados){
  cout << "Puerto: " << a << endl;}
}

#endif /* Actividad1_3_hpp */