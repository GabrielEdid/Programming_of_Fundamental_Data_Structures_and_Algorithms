//  Hecho por Gabriel Edid A01782146
//  16/10/2023
//  Actividad 3.1 - Operaciones avanzadas en un BST
//  main.cpp

#include <iostream>
#include <vector>
#include "Clases/TreeNode.hpp"
#include "Clases/BinaryTree.hpp"
#include "Clases/BST.hpp"
using namespace std;

int main(int argc, const char * argv[]){
    BST<int> * arbol1 = new BST<int>();
    BST<int> * arbol2 = new BST<int>();
    BST<int> * arbol3 = new BST<int>();
    BST<int> * arbol4 = new BST<int>();

    vector<int>nodes1{5,2,8,1,4,7,9,0,3,6,10};
    vector<int>nodes2{60,30,90,10,40,70,100,20,50,80,110};
    vector<int>nodes3{55,18,101,9,45,91,7777,16,54,128,987};
    vector<int>nodes4{20,8,28,7,16,27,30,2,11,10,21};

    //Crear los 4 arboles para los 4 casos de prueba
    for(auto a : nodes1){
        TreeNode<int> * x = new TreeNode<int>(a);
        arbol1->insert(x);
    }
     for(auto a : nodes2){
        TreeNode<int> * x = new TreeNode<int>(a);
        arbol2->insert(x);
    }
     for(auto a : nodes3){
        TreeNode<int> * x = new TreeNode<int>(a);
        arbol3->insert(x);
    }
     for(auto a : nodes4){
        TreeNode<int> * x = new TreeNode<int>(a);
        arbol4->insert(x);
    }
    
    int opcion;
    bool continuar = true;
    do {
    cout << "\n¿Qué árbol deseas usar: 1, 2, 3 o 4? ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            arbol1 -> visit();
            arbol1 -> height();
            arbol1 -> ancestro();
            arbol1 -> whatLevelamI();         
            continuar = false; 
            break;
        case 2:
            arbol2 -> visit();
            arbol2 -> height();
            arbol2 -> ancestro();
            arbol2 -> whatLevelamI();           
            continuar = false; 
            break;
        case 3:
            arbol3 -> visit();
            arbol3 -> height();
            arbol3 -> ancestro();
            arbol3 -> whatLevelamI(); 
            continuar = false;
            break;
        case 4:
            arbol4 -> visit();
            arbol4 -> height();
            arbol4 -> ancestro();
            arbol4 -> whatLevelamI(); 
            continuar = false;  
            break;
        default:
            cout << "\nOpción Invalida! Inténtalo de nuevo." << endl;
            break;
    }

} while (continuar);
delete arbol1;
delete arbol2;
delete arbol3;
delete arbol4;

return 0;
}