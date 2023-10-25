//
//  BST.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 20/10/20.
//  Modificado por Gabriel Edid A01782146

#ifndef BST_hpp
#define BST_hpp

#include "BinaryTree.hpp"

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    BST() {};
    virtual ~BST() { };
    
    TreeNode<T> * search(const T &) const;
    bool insert(T &);
    bool insert(TreeNode<T> * );
    
    int whatlevelamIprof(const T &) const;

    void height() const;
    int height(TreeNode<T> *) const;

    void LevelByLevel() const;

    void visit() const;
    void visit(int) const;

    void ancestro() const;
    void ancestro(int) const;

    void whatLevelamI() const;
    int whatLevelamI(TreeNode<T> *, const T &, int) const;

    TreeNode<T> * sucesor(TreeNode<T> *) const;
    TreeNode<T> * predecesor(TreeNode<T> *) const;
    TreeNode<T> * remove(T);
    
private:
    /* Ocultar algunos métodos heredados */
    //using BinaryTree<T>::insert;
};

/*
 Complejidad: O(log n) si el árbol está 4nceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
TreeNode<T> * BST<T>::search(const T & value) const
{
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            return aux;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    return nullptr;
}

/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
bool BST<T>::insert(T & value)
{
    return this->insert(new TreeNode<T>(value));
}

template <class T>
bool BST<T>::insert(TreeNode<T> * node )
{
    /* No se puede insertar un nodo NULL */
    if (node == nullptr) return false;
    
    /* Obtener la info del nodo a insertar */
    T value = node->getInfo();
    
    /* Establecer un apuntador auxiliar */
    TreeNode<T> * aux = this->root;
    
    /* Estalecer una variable para el padre */
    TreeNode<T> * parent = nullptr;
    
    /* Buscar la posición que le corresponde */
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            /* Liberar la memoria del nodo porque ya existe */
            delete node;
            
            return false;
        }
        else {
            parent = aux;
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    /* Establecer el parent del nodo a insertar */
    node->setParent(parent);
    
    /* Si el árbol está vacío, se inserta la raiz */
    if (parent == nullptr) {
        this->root = node;
    }
    else {
        /* Si el value a insertar es menor, se inserta a la izquierda */
        if ( parent->getInfo() > value ) {
            parent->setLeft(node);
        }
        /* Si el value a insertar es mayor, se inserta a la derecha */
        else {
            parent->setRight(node);
        }
    }
    
    return true;
}

/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
int BST<T>::whatlevelamIprof(const T & value) const
{
    int level = 0;
    
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        level++;
        if (aux->getInfo() == value) {
            return level;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    if (aux == nullptr) {
        level = 0;
    }
    
    return level;
}

/* Función Visit:
En el peor de los casos o cuando el arbol tiene elementos O(n), o sea que lineal.
En el mejor caso igualmente habría una complejidad de O(n) ya que debe de recorrer todos los nodos para determinar la altura */

template <class T>
void BST<T>::height() const
{
    std::cout << "\n---HEIGHT---" << std::endl;
    int altura = height(this->root);
    std::cout << "La altura del árbol es: " << altura << std::endl;
}

template <class T>
int BST<T>::height(TreeNode<T> * node) const
{
    if (node == nullptr) {
        return 0; 
    }

    int leftHeight = height(node->getLeft());
    int rightHeight = height(node->getRight());

    return 1 + std::max(leftHeight, rightHeight);
}

template <class T>
void BST<T>::LevelByLevel() const
{
    if (this->root == nullptr) {
        return;
    }

    std::queue<TreeNode<T>*> q;
    q.push(this->root);

    while (!q.empty()) {
        
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode<T> * current = q.front();
            q.pop();

            std::cout << *current << " ";

            if (current->getLeft() != nullptr) q.push(current->getLeft());
            if (current->getRight() != nullptr) q.push(current->getRight());
        }

        std::cout << std::endl; 
    }
}

/* Función Visit:
En el peor de los casos o cuando el arbol tiene elementos O(n), o sea que lineal.
En el caso en el que el arbol este vacío habria una complejidad de O(1) */

template <class T>
void BST<T>::visit() const 
{
    std::cout << "\n---VISIT---" << std::endl;
    std::cout << "Elige una Opcion, 1- PreOrder, 2- InOrder, 3- PostOrder, 4- LevelByLevel: "; 
    int opcion;
    std::cin >> opcion;
    visit(opcion);
}

template <class T>
void BST<T>::visit(int opcion) const 
{
    switch(opcion){
        case 1:
            std::cout << "Arbol en PreOrden: "; 
            this->preOrden();
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Arbol inOrden: "; 
            this->inOrden();
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Arbol en postOrden: "; 
            this->postOrden();
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "Arbol en LevelByLevel: " << std::endl;
            this->LevelByLevel();
            std::cout << std::endl;
            break;
    }
}

/* Función Ancestro:
En el peor de los casos o cuando el arbol esta desequilibrado tiene una complejidad de O(n), o sea que lineal.
En el caso en el que el BST este equilibrado tendría una complejidad de O(log n) */

template <class T>
void BST<T>::ancestro() const 
{
    std::cout << "\n---ANCESTORS---" << std::endl;
    int valor;
    std::cout << "¿Sobre que valor deseas saber sus ancestros en el árbol? ";
    std::cin >> valor;
    ancestro(valor);
}

template <class T>
void BST<T>::ancestro(int busca) const 
{
    TreeNode<int> * exist = this->search(busca); 
    TreeNode<int> * parent = (exist != nullptr) ? exist->getParent() : nullptr;
    int i = 0;
    
    if (parent == nullptr){
        std::cout << "El valor no esta en el arbol o es la raiz" << std::endl;
    }

    while(parent != nullptr){
        i++;
        std::cout << "Ancestro " << i << " : " << parent->getInfo() << std::endl; 

        exist = parent;
        parent = exist->getParent(); 
    }
};

/* Función WhatLevelamI:
En el peor de los casos o cuando el arbol esta desequilibrado tiene una complejidad de O(n), o sea que lineal.
En el caso en el que el BST este equilibrado tendría una complejidad de O(log n) */

template <class T>
void BST<T>::whatLevelamI() const
{
    std::cout << "\n---WHAT_LEVEL_AM_I---" << std::endl;
    int valor;
    std::cout << "¿Sobre que valor deseas saber el nivel en el arbol? ";
    std::cin >> valor;

    int nivel = whatLevelamI(this->root, valor, 1);
    
    if (nivel != -1) {
        std::cout << "El valor " << valor << " está en el nivel: " << nivel << std::endl;
    } else {
        std::cout << "El valor " << valor << " no se encuentra en el árbol." << std::endl;
    }
}

template <class T>
int BST<T>::whatLevelamI(TreeNode<T> * nodo, const T & valor, int nivel) const
{
    if (nodo == nullptr) {
        return -1;  // No encontrado.
    }
    
    if (nodo->getInfo() == valor) {
        return nivel;
    }
    
    if (nodo->getInfo() > valor) {
        return whatLevelamI(nodo->getLeft(), valor, nivel + 1);
    } else {
        return whatLevelamI(nodo->getRight(), valor, nivel + 1);
    }
}

#endif /* BST_hpp */