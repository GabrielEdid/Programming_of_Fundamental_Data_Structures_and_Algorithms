// Gabriel Edid Harari A01782146
// Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
// 10/09/2023
// main.cpp

//Imports
#include "Clases/Camioneta.hpp"
#include "Clases/Comprador.hpp"
#include "Clases/Motocicleta.hpp"
#include "Clases/Vehiculo.hpp"
#include "Clases/Venta.hpp"
#include "Clases/Ordenamiento.hpp"
#include "Clases/Busqueda.hpp"
#include <iostream>
#include <vector>
using namespace std;

//Variables a Utilizar 
int codigo, ano, kilometraje, monto, INE, opMenu, opVehic, continuar, kilomBuscar, anoBuscar;
string marca, modelo, traccion, cilindraje, nombre, apellido, nombreBuscar;

void Formulario() {
  cout << "Introduce el Monto de la Compra: "; cin >> monto;
  cout << "Introduce el Nombre del Comprador: "; cin >> nombre;
  cout << "Introduce el Apellido del Comprador: "; cin >> apellido;
  cout << "Introduce la INE del Comprador: "; cin >> INE;
  cout << "Introduce la Marca del Vehiculo: "; cin >> marca;
  cout << "Introduce el Modelo del Vehiculo: "; cin >> modelo;
  cout << "Introduce el Año del Vehiculo: "; cin >> ano;
  cout << "Introduce el Kilometraje del Vehiculo: "; cin >> kilometraje;
  cout << "Introduce el Codigo del Vehiculo: "; cin >> codigo;
};

int main() {
  vector<Venta *> ventas, ventaNombre, ventaAnoKilom;
  //CASOS DE PRUEBA
  {
  auto vehicV = new Vehiculo{8743468, "Tesla", "ModelX", 2023, 1001};
  auto compV = new Comprador{4567, "Gabriel", "Edid"};
  auto ventV = new Venta{1500000, vehicV, compV};
  ventas.push_back(ventV); //COCHE
  auto vehicC = new Camioneta{5676543, "Infinity", "QX60", 2021, 100, "4x4"};
  auto compC = new Comprador{7654, "Salomon", "Harari"};
  auto ventC = new Venta{900000, vehicC, compC};
  ventas.push_back(ventC); //CAMIONETA
  auto vehicM = new Motocicleta{6724, "Harley Davidson", "Cruiser", 2021, 500, "150cc"};
  auto compM = new Comprador{198753, "Juan", "Gallardo"};
  auto ventM = new Venta{50000, vehicM, compM};
  ventas.push_back(ventM); //MOTOCICLETA
  auto vehicC1 = new Camioneta{2828, "Range Rover", "Velar", 2023, 7000, "4x2"}; 
  auto compC1 = new Comprador{0707, "Juan", "Jimenez"};
  auto ventC1 = new Venta{700000, vehicC1, compC1};
  ventas.push_back(ventC1); //CAMIONETA
  }
  //FIN CASOS DE PRUEBA

  //While para Mantenerse en el Menu
  while (true) {
    cout << "\n*** Bienvenido al Sistema de Registro de Vehiculos *** \n"
         << endl;
    cout << "Que deseas hacer?\n1- Añadir una Venta\n2- Mostrar Ventas\n3- Mostrar Vehiculos por Nombre\n4- Mostrar Vehiculos por Kilometraje y Año\nPara Salir Presiona Cualquier Otra Tecla \nOpcion: ";
    cin >> opMenu;

    switch (opMenu) {
    case 1: {
      cout << "\nQue tipo de Vehiculo deseas Ingresar?\n1- Coche\n2- Camioneta\n3- Motocicleta\nPara Regresar Presiona Cualquier Otra Tecla\nOpcion: ";
      cin >> opVehic;
      switch (opVehic) {
      case 1: {
        Formulario();
        auto vehicV = new Vehiculo{codigo, marca, modelo, ano, kilometraje};
        auto compV = new Comprador{INE, nombre, apellido};
        auto ventV = new Venta{monto, vehicV, compV};
        ventas.push_back(ventV);
        cout << "\n *** VENTA REGISTRADA *** \n" << endl;
        break;
      } // Case 1 Inner Switch
      case 2: {
        Formulario();
        cout << "Introduce la Tracción de la Camioneta: ";
        cin >> traccion;
        auto vehicC = new Camioneta{codigo, marca, modelo, ano, kilometraje, traccion};
        auto compC = new Comprador{INE, nombre, apellido};
        auto ventC = new Venta{monto, vehicC, compC};
        ventas.push_back(ventC);
        cout << "\n *** VENTA REGISTRADA *** \n" << endl;
        break;
      } // Case 2 Inner Switch
      case 3: {
        Formulario();
        cout << "Introduce el Cilindraje de la Motocicleta: ";
        cin >> cilindraje;
        auto vehicM = new Motocicleta{codigo, marca, modelo, ano, kilometraje, cilindraje};
        auto compM = new Comprador{INE, nombre, apellido};
        auto ventM = new Venta{monto, vehicM, compM};
        ventas.push_back(ventM);
        cout << "\n *** VENTA REGISTRADA *** \n" << endl;
        break;
      } // Case 3 Inner Switch
      default:
      break;
      } // Inner Switch
      break;
    } // Case 1 Outter Switch
    case 2: {
      
      ventas = Ordenamiento<Venta>::quicksort(ventas, 0, ventas.size() - 1, &Venta::monto_desc);
      cout << "\n*** Ventas Ordenadas por Monto($) ***\n" << endl; 
      for (auto a : ventas) {
        cout << *a << endl;}
      break;
    } // Case 2 Outter Switch
    case 3: {
      cout << "\nIntroduce el Nombre que deseas buscar: "; cin >> nombreBuscar;
      ventaNombre = Busqueda<Venta>::busquedaSecuencialNombre(ventas, nombreBuscar);
      cout << "\nLos Vehiculos encontrados con el nombre de " << nombreBuscar << " son: \n" << endl;
      for (auto a : ventaNombre) {
        cout << *a << endl; }
    break;
    } // Case 3 Outter Switch
    case 4: {
      cout << "\nIntroduce el Año del Vehiculo que deseas buscar: "; cin >> anoBuscar;
      cout << "Introduce el Kilometraje que deseas buscar: "; cin >> kilomBuscar;
      ventaAnoKilom = Busqueda<Venta>::busquedaSecuencialAnoKilom(ventas, anoBuscar, kilomBuscar);
      cout << "\nLos Vehiculos encontrados del Año " << anoBuscar << " con un Kilometraje menor o igula a " << kilomBuscar << " son: \n" << endl;
      for (auto a : ventaAnoKilom) {
        cout << *a << endl; }
    break;
    } // Case 4 Outter Switch
    default:
      cout << "\n¿Seguro que deseas salir?\n(1: Sí / 0: No): ";
      cin >> continuar;
      if (continuar == 1) {
        return 0;
      } //If Statement
    } // Outter Switch
  } // While
} //Main