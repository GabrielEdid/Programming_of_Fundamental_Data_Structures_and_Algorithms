//  Gabriel Edid Harari A01782146
//  Actividad 2.1 - Programación de Estructuras de Datos y Algoritmos Fundamentales
//  29/09/2023

#include <iostream>
#include <vector>
#include "Clases/Node.hpp"
#include "Clases/LinkedList.hpp"
using namespace std;


void SubList(LinkedList<int> * lista, int from, int to) {
    //Guardar los elementos de from y to en una nueva variable porque van a ser modificados
    int fromS = from; 
    int toS = to;
    LinkedList<int> * fromToList = new LinkedList<int>();

    Node<int> *current = lista->at(from);

    while (current != nullptr && from <= to) {
        fromToList->insert_back(current->getInfo());
        current = current->getNext();
        ++from;
    }

    cout << "La nueva lista generada del elemento " << fromS << " hasta el elemento " << toS << " es: " << *fromToList << endl;
    delete fromToList;
}
/* Esta función tiene una complejidad coputacional de O(form-to) en cualquier de los casos debido a que se tiene un while loop
que siempre recorrera los valores de from hasta to, se podría establecer que la complejidad es O(n) en el peor de los casos. */

void DeleteRange(LinkedList<int> * lista, int from, int to) {
    LinkedList<int> * deleteFromTo = new LinkedList<int>();

    for(int i = 0; i < lista -> size(); i++){
        if (i >= from && i <= to){
            continue;
        }
        else{
            Node<int> *current = lista->at(i);
            deleteFromTo->insert_back(current->getInfo());
        }
    }

    cout << "La nueva lista generada eliminando del elemento " << from << " hasta el elemento " << to << " es: " << *deleteFromTo << endl;
    delete deleteFromTo;
}
/* Esta función tiene una complejidad coputacional de O(n) en cualquier de los casos debido a que tiene un for loop
que siempre recorrera todos los datos de la listaA. */

void Union(LinkedList<int> * listaA, LinkedList<int> * listaB) {
    LinkedList<int> * nuevaUnion = listaA -> clone();

    for(int i = 0; i < listaB -> size(); i++){
        Node<int> *current = listaB->at(i);
        nuevaUnion->insert_back(current->getInfo());
        }

    cout << "La nueva lista generada uniendo las listas A y B es: " << *nuevaUnion << endl;
    delete nuevaUnion;
}
/* Esta función tiene una complejidad coputacional de O(n) en cualquier de los casos debido a que tiene un for loop
que siempre recorrera todos los datos de la listaB. */

void Intersection(LinkedList<int> * listaA, LinkedList<int> * listaB){
    LinkedList<int> * nuevaIntersection = new LinkedList<int>();

    for(int i = 0; i < listaA -> size(); i++){
        Node<int> *currentA = listaA->at(i);

            for(int j = 0; j < listaB -> size(); j++){
                Node<int> *currentB = listaB->at(j);

                if (*currentA == *currentB){
                    nuevaIntersection -> insert_back(currentB -> getInfo());
                }
            }
    }
    cout << "La nueva lista uniendo los datos iguales de las listas A y B es: " << *nuevaIntersection << endl;
    delete nuevaIntersection;
}
/* Esta función tiene una complejidad coputacional de O(n^2) en cualquier de los casos debido a que tiene dos for loops anidados.
Es decir que la función iterara a través de todos los datos de ambas listas cada vez que se corra el loop */

void Except(LinkedList<int> * listaA, LinkedList<int> * listaB){

    for(int i = 0; i < listaA -> size(); i++){
        Node<int> *currentA = listaA->at(i);

            for(int j = 0; j < listaB -> size(); j++){
                Node<int> *currentB = listaB->at(j);

                if (*currentA == *currentB){
                    listaA -> remove(currentA);
                    listaB -> remove(currentB);
                    delete currentA;
                    delete currentB;
                }
            }
    }
    LinkedList<int> * nuevaExcept = listaA -> clone();
        for(int i = 0; i < listaB -> size(); i++){
        Node<int> *current = listaB->at(i);
        nuevaExcept->insert_back(current->getInfo());
        }
    cout << "La nueva lista uniendo los datos diferentes de las listas A y B es: " << *nuevaExcept << endl;
    delete nuevaExcept;
}
/* Esta función tiene una complejidad coputacional de O(n^2) en cualquier de los casos debido a que tiene dos for loops anidados.
Es decir que la función iterara a través de todos los datos de ambas listas cada vez que se corra el loop */


int main(){

    //Numeros para las listas A y B
    vector <int> numerosA{0,1,2,3,4,5,6,7,8,9};
    vector <int> numerosB{7,2,28,27,5,30,16,20};

    //Generar la listaA
    LinkedList<int> * listaA = new LinkedList<int>();
    for (int i=0; i < numerosA.size(); i++ ){
    listaA -> insert(numerosA[i],i); }

    //Generar la listaB
    LinkedList<int> * listaB = new LinkedList<int>();
    for (int i=0; i < numerosB.size(); i++ ){
    listaB -> insert(numerosB[i],i); }

    //Problemas que usan la listaA
    cout << "\n*** La lista con la que se estara trabajando esta compuesta por: " << *listaA << " (listaA) ***" << endl;
   
    cout << "\n---SubList---" << endl;
    SubList(listaA, 2, 6);

    cout << "\n---DeleteRange---" << endl;
    DeleteRange(listaA,3,5);

    //Problemas que usan la listaA y la listaB
    cout << "\n*** A partir de ahora se estara trabajando con la listaA y con la siguiente lista: " << *listaB  << " (listaB) ***" << endl;

    cout << "\n---Union---" << endl;
    Union(listaA,listaB);

    cout << "\n---Intersection---" << endl;
    Intersection(listaA,listaB);

    cout << "\n---Except---" << endl;
    Except(listaA,listaB);
    
    delete listaA;
    delete listaB;
    cout << "\nMemoria de todas las Listas Eliminada, incluyendo las listas dadas por las funciones.\n" << endl;
    return 0;
}