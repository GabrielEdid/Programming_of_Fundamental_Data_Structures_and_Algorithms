// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// 21/09/2023
// main.cpp

#include "Clases/Busqueda.hpp"
#include "Clases/Ordenamiento.hpp"
#include "Clases/Registro.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <set>
using namespace std;


vector<Registro> read_csv_registro(string filename) {
  /* Crear un vector de vector de strings */
  vector<Registro> lineas;

  /* Crear un input filestream para leer el archivo CSV */
  ifstream file(filename);

  /* Verificar si no hubo error al abrir el archivo */
  if (!file.is_open())
    throw runtime_error("No se puede abrir el archivo");

  /* Definir variable que almacena cada línea */
  string linea;

  /* Leer datos línea a línea */
  while (getline(file, linea)) {
    /* Crear un steam de la línea */
    stringstream ss(linea);

    /* Variables que almacenan cada campo leído */
    string fecha, hora, ipOrigen, nombreOrigen, ipDestino, nombreDestino, puertoOrigen, puertoDestino;

    /* Iterar sobre la línea para extraer cada campo */
    getline(ss, fecha, ',');
    getline(ss, hora, ',');
    getline(ss, ipOrigen, ',');
    getline(ss, puertoOrigen, ',');
    getline(ss, nombreOrigen, ',');
    getline(ss, ipDestino, ',');
    getline(ss, puertoDestino, ',');
    getline(ss, nombreDestino, ',');
    // ss >> edad;

    /* Insertar la fila con los campos separados en un vector */
    lineas.push_back(Registro(fecha, hora, ipOrigen, puertoOrigen, nombreOrigen, ipDestino, puertoDestino, nombreDestino));
  }

  /* Cerrar el archivo */
  file.close();

  /* Regresar el vector de líneas leídas */
  return lineas;
}

int main() {

  /* Lectura de los datos como un objeto Persona */
  vector<Registro> registros = read_csv_registro("equipo3.csv");

  // Pregunta 1 - ¿Cuantos Registros Hay?
  {
  cout << "El total de registros dentro del archivo es de: " << registros.size()
       << endl;
  }

  // Pregunta 2 - ¿Cuántos records hay el segundo día registrado? ¿Que día es ese? 
  {
  //  Se ordena el vector personas
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
  
  //Pregunta 3 - ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?
  {
  cout << endl;
  vector<string> nombresBuscar{"jeffrey", "betty", "katherine", "scott", "benjamin", "samuel", "raymond"};
  
  for(auto a: nombresBuscar){
    int buscar = Busqueda<Registro>::busquedaSecuencialNombreOr(registros, a + ".reto.com");
    cout << "El numero de registros encontrados para " << a << " es de: " << buscar << endl; }
  }
  
  //Pregunta 4 - ¿Cuál es la dirección de la red interna de la compañía?
  {
    int punto=0;
    string direccionIP="";
    string registroIP; 
    int in = 0; 
    for (auto a:registros){
      if (registros[in].ipOrigen != "-") {
        registroIP = registros[in].ipOrigen;
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
  }  

  //Pregunta 5 - ¿Alguna computadora se llama server.reto.com? 
  {
  string server = "server.reto.com";
  int serverEncontrado = Busqueda<Registro>::busquedaSecuencialNombreOr(registros, server);
  cout << "\nSe encontraron " << serverEncontrado << " registros con el nombre " << server << endl;
  }

  //Pregunta 6 - ¿Qué servicio de correo electrónico utilizan? 
  {
  cout << endl;
  vector <string> correos {"google.com","hotmail.com", "outlook.com", "protonmail.com", "freemailserver.com", "mail.yahoo.com" };
  for (auto a:correos){
  int correoEcontrado = Busqueda<Registro>::busquedaSecuencialCorreo(registros, a);
  cout << "Se encontraron " << correoEcontrado << " registros con el correo " << a << endl;
    }
  }

  //Pregunta 7 - Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando?
  {
  cout << "\nPuertos menores a 1000" << endl;
  set <string> puertosEncontrados = Busqueda<Registro>::busquedaSecuencialPuertos(registros, 1000);
  //cout << "Se encontraron " << correoEcontrado << " registros con el correo " << a << endl;
    for (auto a:puertosEncontrados){
    cout << "Puerto: " << a << endl;}
  }

  return 0;
}