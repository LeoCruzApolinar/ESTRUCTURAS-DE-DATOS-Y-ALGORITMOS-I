/*
Enunciado    :    Arboles
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
                  Alexa  Guzmán          ID:  1101488
                  José L. Cruz           ID:  1106529
                  Eros Bencosme          ID:  1104510
Fecha        :    26/09/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cctype>

using namespace std;

struct Node {
    int dato;
    Node* izq;
    Node* der;
    Node* padre;
};

void menu();
Node* createNode(int, Node*);
void insertar(Node*&, int, Node*);
void eliminarNode(Node*&, Node*&);
void eliminar_UnHijo(Node*&, Node*&, Node*&);
void eliminar_SinHijos(Node*&, Node*&);
void eliminar_DosHijos(Node*&, Node*&);
bool EsHijoDerecho(Node*&);
void mostrar(Node*, int);
bool buscar(Node*, int);
void preOrden(Node*);
void inOrden(Node*);
void postOrden(Node*);
Node* min(Node*);
void destroyNode(Node*&);
Node* ubicar(Node*&, int);

Node* arbol = NULL;

// Crear un nodo
Node* createNode(int n, Node* padre) {
    Node* newNode = new Node();
    newNode->dato = n;
    newNode->izq = NULL;
    newNode->der = NULL;
    newNode->padre = padre;
    return newNode;
}

// Insertar un nodo en el arbol
void insertar(Node*& arbol, int n, Node* padre) {
    if (arbol == NULL) { // Si el arbol esta vacio
        Node* newNode = createNode(n, padre); // Crear un nuevo nodo
        arbol = newNode;
    }
    else { // Si el arbol no esta vacio
        int root = arbol->dato; // Busca el dato de la raiz

        if (n < root) { // Si el nodo es menor que la raiz
            insertar(arbol->izq, n, arbol); // Se coloca en la izquierda
        }
        else { // Si el nodo es mayor que la raiz
            insertar(arbol->der, n, arbol); // Se coloca en la derecha
        }
    }
}

// Mostrar el arbol
void mostrar(Node* arbol, int count) {
    if (arbol == NULL) // Si el arbol esta vacio
        return;
    mostrar(arbol->der, count + 1); // Invoca la funcion de manera recursiva, muestra el subarbol derecho

    for (int i = 0; i < count; i++)
        cout << "   ";

    cout << arbol->dato << endl;
    mostrar(arbol->izq, count + 1); // Invoca la funcion de manera recursiva, muestra el subarbol derecho

}

// Buscar un nodo
bool buscar(Node* arbol, int n) {
    if (arbol == NULL) { // Si el arbol esta vacio
        return false;
    }
    else if (arbol->dato == n) { // Si el nodo que se busca es igual a la raiz
        return true;
    }
    else {
        return false;
    }
    if (n < arbol->dato) { // Si el numero a buscar es menor que la raiz, se busca en el lado izquierdo
        return buscar(arbol->izq, n);
    }
    else { // Si el numero a buscar es menor que la raiz, se busca en el lado derecho
        return buscar(arbol->der, n);
    }
}

// Recorrido preOrder
void preOrder(Node* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " - ";
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

// Recorrido inOrder
void inOrder(Node* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrder(arbol->izq);
        cout << arbol->dato << " - ";
        inOrder(arbol->der);
    }
}

// Recorrido postOrder
void postOrder(Node* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        cout << arbol->dato << " - ";
    }
}

// Determinar el nodo mas a la izquierda
Node* min(Node* arbol) {
    if (arbol == NULL) { // Si el arbol esta vacio
        return NULL;
    }
    if (arbol->izq) { // Si tiene nodos a la izquierda
        return min(arbol->izq); // Devuelve el nodo mas a la izquierda
    }
    else { // Si no tiene nodos a la izquierda, devuelve la raiz
        return arbol;
    }
}

// Destruir nodo
void destroyNode(Node*& deleteNode) {
    deleteNode->izq = NULL;
    deleteNode->der = NULL;
    deleteNode->padre = NULL;

    delete deleteNode;
}

// Eliminar el nodo encontrado
void eliminarNode(Node*& deleteNode, Node*& raiz) {
    if (deleteNode->izq == NULL && deleteNode->der == NULL) { // Si el nodo no tiene hijos
        eliminar_SinHijos(deleteNode, raiz);
    }
    else if (deleteNode->izq != NULL && deleteNode->der != NULL) { // Si el nodo tiene dos hijos
        eliminar_DosHijos(deleteNode, raiz);
    }
    else if (deleteNode->der != NULL) { // Si solo tiene hijo derecho
        eliminar_UnHijo(deleteNode, deleteNode->der, raiz);
    }
    else if (deleteNode->izq != NULL) { // Si solo tiene hijo izquierdo
        eliminar_UnHijo(deleteNode, deleteNode->izq, raiz);
    }
}

// Eliminar un nodo con un solo hijo
void eliminar_UnHijo(Node*& deleteNode, Node*& hijo, Node*& raiz) {
    if (deleteNode->padre != NULL) { // Si el nodo a borrar tiene padre
        hijo->padre = deleteNode->padre; // Al nodo hijo le asignamos como nuevo padre a su "abuelo"

        if (EsHijoDerecho(deleteNode)) { // Si es un hijo derecho
            deleteNode->padre->izq = hijo; // Al nodo padre le asignamos como nuevo hijo a su "nieto"
        }
        else { // Si es un hijo izquierdo
            deleteNode->padre->der = hijo;
        }
    }
    else if (raiz == deleteNode) { // Si el nodo a borrar es la raiz
        arbol = hijo;
        arbol->padre = NULL; // No tiene padre
    }
    destroyNode(deleteNode);
}

// Eliminar un nodo con dos hijos
void eliminar_DosHijos(Node*& deleteNode, Node*& raiz) {
    Node* minimo = min(deleteNode->izq); // Buscando el valor mas cercano al dato a borrar
    deleteNode->dato = minimo->dato; // El nodo a borrar será reemplazado
    eliminarNode(minimo, raiz);
}

void eliminar_SinHijos(Node*& deleteNode, Node*& raiz) {
    if (deleteNode->padre != NULL) { // Si el nodo no tiene padre
        if (EsHijoDerecho(deleteNode)) { // Si el nodo es un hijo derecho
            deleteNode->padre->der = NULL;
        }
        else { // Si el nodo es un hijo izquierdo
            deleteNode->padre->izq = NULL;
        }
    }
    else if (raiz == deleteNode) { // Si el nodo a borrar es la raiz
        raiz = NULL;
    }
    destroyNode(deleteNode);
}

bool EsHijoDerecho(Node*& hijo) { // Determina si es un hijo derecho
    if (hijo->padre->der == hijo) {
        return true;
    }
    return false;
}

Node* ubicar(Node*& arbol, int find) { // Puntero para ubicar el nodo a eliminar
    if (arbol == NULL || arbol->dato == find) { // Si el nodo a eliminar es la raiz
        return arbol; // Se devuelve la raiz
    }
    if (find < arbol->dato) { // Si es menor que la raiz, se busca por la izquierda
        ubicar(arbol->izq, find);
    }
    else { // Si es menor que la raiz, se busca por la derecha
        ubicar(arbol->der, find);
    }
}

void menu() {

    int dato, opcion, contador = 0;
    char str[100];

    do {
        cout << "\n*************************************" << endl;
        cout << "*    ARBOLES BINARIOS DE BUSQUEDA   *" << endl;
        cout << "*************************************\n" << endl;
        cout << "[1] Insertar nodo" << endl;
        cout << "[2] Eliminar nodo" << endl;
        cout << "[3] Mostrar arbol" << endl;
        cout << "[4] Buscar un numero en el arbol" << endl;
        cout << "[5] Recorrer en PreOrder" << endl;
        cout << "[6] Recorrer en InOrder" << endl;
        cout << "[7] Recorrer en PostOrder" << endl;
        cout << "[8] Salir" << endl;

        do {
            cout << "Opcion: ";
            cin >> str;
            while ((isalpha(str[0])))//Verifica si es de tipo letra
            {
                cout << "Por favor, ingrese del 1 al 8, no utilice letras\n";
                cout << "Opcion: ";
                cin >> str;//validacion de datos

            };
            opcion = atoi(str); //Convierte la variable str a tipo numerico
            if (opcion > 8 || opcion < 1)
            {
                cout << "Por favor, ingrese un numero del 1 al 8\n";
            }
        } while ((opcion > 8) || (opcion < 1));
        str[0] = NULL;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese un numero: ";
            cin >> str;
            while ((isalpha(str[0])))
            {
                cout << "Las letras no estan permitidas" << endl;
                cout << "\nIngrese un numero: ";
                cin >> str;
            }
            dato = atoi(str);
            str[0] = NULL;
            insertar(arbol, dato, NULL);
            cout << "\n";
            system("pause");
            break;
        case 2:

            if (arbol == NULL) {
                cout << "Arbol Vacio" << endl << endl;
                system("pause");
            }
            else {
                cout << "Ingrese el numero a eliminar: ";
                cin >> str;
                while ((isalpha(str[0])))
                {
                    cout << "Las letras no estan permitidas" << endl;
                    cout << "\nIngrese un numero a eliminar: ";
                    cin >> str;
                }
                dato = atoi(str);
                str[0] = NULL;
                Node* borrar = ubicar(arbol, dato);
                system("cls");
                if (borrar == NULL) {
                    cout << "El elemento no esta en el arbol" << endl << endl;
                    system("pause");
                }
                else {
                    eliminarNode(borrar, arbol);
                    cout << "Elemento " << dato << " Eliminado" << endl << endl;
                    system("pause");
                }
            }
            break;

        case 3:
            cout << "Mostrando el arbol: " << endl;
            if (arbol == NULL) {
                cout << "No hay datos en el arbol";
            }
            else {
                mostrar(arbol, contador);
            }
            cout << "\n";
            system("pause");
            break;

        case 4:
            cout << "Ingrese el numero a buscar: " << endl;
            cin >> str;
            while ((isalpha(str[0])))
            {
                cout << "Las letras no estan permitidas" << endl;
                cout << "\nIngrese un numero a buscar: ";
                cin >> str;
            }
            dato = atoi(str);
            str[0] = NULL;
            if (buscar(arbol, dato) == true) {
                cout << "El numero " << dato << " se encuentra en el arbol" << endl;
            }
            else {
                cout << "El numero " << dato << " no se encuentra en el arbol" << endl;
            }
            system("pause");
            break;

        case 5:
            cout << "Mostrando en PreOrder: " << endl;
            if (arbol == NULL) {
                cout << "El arbol esta vacio" << endl;
            }
            else {
                preOrder(arbol);
            }
            cout << "\n\n";
            system("pause");
            break;

        case 6:
            cout << "Mostrando en InOrder: " << endl;
            if (arbol == NULL) {
                cout << "El arbol esta vacio" << endl;
            }
            else {
                inOrder(arbol);
            }
            cout << "\n\n";
            system("pause");
            break;

        case 7:
            cout << "Mostrando en PostOrder: " << endl;
            if (arbol == NULL) {
                cout << "El arbol esta vacio" << endl;
            }
            else {
                postOrder(arbol);
            }
            cout << "\n\n";
            system("pause");
            break;

        }
        system("cls");
    } while (opcion != 8);
}

int main()
{
    menu();
}