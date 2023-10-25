// Gabriel Edid Harari A01782146 y Paolo Antonio Pires Cano A01749355
// Actividad 2.2 - Actividad Integral Estructura de Datos Lineales
// 09/10/2023
// main.cpp

#include "Clases/Registro.hpp"
#include "Clases/ConexionesComputadora.hpp"
#include "Clases/Actividades/Actividad1.3.hpp"
#include "Clases/Actividades/Actividad2.2.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;
//#include <cstdlib> incluir para dividir las actividades
//#include <unistd.h> incluir para dividir las actividades

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

  /* Lectura de los datos como un objeto Registro */
  vector<Registro> registros = read_csv_registro("equipo3.csv");
  
  // Inicio Actividad 1.3
  
  cout << "\n-------- Actividad 1.3 --------" << endl;
  
  Actividad1_3<Registro>::pregunta1(registros);
  
  Actividad1_3<Registro>::pregunta2(registros);
  
  Actividad1_3<Registro>::pregunta3(registros);
  
  string direccionIP = Actividad1_3<Registro>::pregunta4(registros);
  
  Actividad1_3<Registro>::pregunta5(registros);
  
  Actividad1_3<Registro>::pregunta6(registros);
  
  Actividad1_3<Registro>::pregunta7(registros);
  
  /*Funciona Para dividir las actividades
  sleep(10);
  system("clear"); */
  
  // Final Actividad 1.3

  cout << "\n-------- Actividad 2.2 --------\n" << endl;

  //Preguntar por la IP a usar
  int ipInterna = Actividad2_2<int>::darIpInterna();

  //Crear el objeto de la clase ConexionesComputadora con la ipInterna dada
  ConexionesComputadora<Registro> Conexiones(direccionIP+to_string(ipInterna), "Conexion1");

  //Buscar las Conexiones con la IP interna dada
  Conexiones.llenarConexiones(registros);
  
  Actividad2_2<int>::pregunta1(direccionIP, ipInterna);

  Actividad2_2<Registro>::pregunta2(Conexiones);

  Actividad2_2<Registro>::pregunta3(Conexiones);
  
  Actividad2_2<Registro>::pregunta4(Conexiones);

  Actividad2_2<Registro>::pregunta5(Conexiones, registros);
  
  // Final Actividad 2.2
  
  return 0;
}