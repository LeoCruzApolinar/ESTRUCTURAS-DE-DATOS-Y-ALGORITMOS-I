/*
Enunciado    :    Linked List(Lista enlazada)
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
                  Alexa  Guzmán          ID:  1101488
                  José L. Cruz           ID:  1106529
                  Eros Bencosme          ID:  1104510
Fecha        :    29/08/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/


#include <iostream>
#include <stdlib.h>

//#include <conio.h> getch();

using namespace std;

struct Node {
    int dato;
    Node* Next;
};

//Prototipo de funciones
void menu();
void verificar();
void insertList(Node*&, int);
void showList(Node*);
void findList(Node* list, int);
void deleteNode(Node*&, int);
void deleteList(Node*&, int&);


Node* list = NULL;
void verificar() {
    system("cls");
    if (list == NULL)
    {
        cout << "La lista esta vacia" << endl;

        system("pause");

        menu();


    }
}//verifica si la lista esta vacia y envia un mensaje
void Noletra() {
    int dato; //declararion de variables para el menu y el programa
    char str[100];
    cin >> str;
    dato = NULL;
    str[0] = NULL;
    while ((isalpha(str[0])))//Verifica si es de tipo letra
    {
        cout << "No usar letras\n";
        cout << "\nDigite el numero que desea buscar: ";
        cin >> str;//validacion de datos

    };

    dato = atoi(str); //Convierte la variable str a tipo numerico
    str[0] = NULL;
}//verrifica que no se use letra
int main() {

    cout << "\tBienvenido al programa de las listas enlazadas!\n ";

    menu(); //Aqui se llama la funcion menu que es la que tiene el switch case con las diferentes opciones
    cout << "El programa se cerrara" << endl;
    system("pause"); //aviso de cierre del programa
    return 0;
}

//Funciones menu, insertar,mostrar,buscar,eliminar

void menu() {

    int opcion, dato; //declararion de variables para el menu y el programa
    char str[100];
    do {
        cout << "----------------------------------------------------\n";
        cout << "\t_____.:MENU:._____\n\n";
        cout << "1. Ingresar elementos a la lista\n";
        cout << "2. Mostrar los elementos de la lista\n";
        cout << "3. Buscar un elemento en la lista\n";
        cout << "4. Eliminar un nodo de la lista\n";
        cout << "5. Vaciar la lista\n";
        cout << "6. Salir\n";

        do {
            cout << "Opcion: ";
            cin >> str;
            while ((isalpha(str[0])))//Verifica si es de tipo letra
            {
                cout << "Por favor, ingrese del 1 al 6, no usar letras\n";
                cout << "Opcion: ";
                cin >> str;//validacion de datos

            };
            opcion = atoi(str); //Convierte la variable str a tipo numerico
            if (opcion > 6 || opcion < 1)
            {
                cout << "Por favor, ingrese un numero del 1 al 6\n";
            }
        } while ((opcion > 6) || (opcion < 1));
        str[0] = NULL;

        switch (opcion) {
        case 1:
            cout << "\n\nIngrese un numero en la lista: ";

            cin >> str;
            while ((isalpha(str[0])))//Verifica si es de tipo letra
            {
                cout << "No usar letras\n";
                cout << "\n\nIngrese un numero en la lista: ";
                cin >> str;//validacion de datos

            };

            dato = atoi(str); //Convierte la variable str a tipo numerico
            str[0] = NULL;



            insertList(list, dato);

            cout << "\n";
            dato = NULL;
            system("pause");
            break;

        case 2:
            verificar();//invoca la funcion verificar la cual verifica si la lista esta vacia

            showList(list);
            cout << "\n";
            system("pause");
            break;

        case 3:
            verificar();//invoca la funcion verificar la cual verifica si la lista esta vacia

            cout << "\nDigite el numero que desea buscar: ";
            cin >> str;
            while ((isalpha(str[0])))//Verifica si es de tipo letra
            {
                cout << "No usar letras\n";
                cout << "\n\nIngrese un numero en la lista: ";
                cin >> str;//validacion de datos

            };

            dato = atoi(str); //Convierte la variable str a tipo numerico
            str[0] = NULL;

            findList(list, dato);
            cout << "\n";
            dato = NULL;
            system("pause");
            break;

        case 4:

            verificar();//invoca la funcion verificar la cual verifica si la lista esta vacia

            cout << "\nIngrese el numero que desea eliminar: ";
            Noletra();//invoca la funcion verificar la cual verifica si se usa letra y evita que se use
            deleteNode(list, dato);
            cout << "\n";
            system("pause");


        case 5:
            verificar();//invoca la funcion verificar la cual verifica si la lista esta vacia
            while (list != NULL) //mientras NO sea el final de la lista, seguira sacando el elemento que haya
            {

                deleteList(list, dato);
                cout << dato << " -> ";

            }



            cout << "\n";

            system("pause");
        }

        system("cls");
    } while (opcion != 6);
}


//Funcion para insertar
void insertList(Node*& list, int n) {
    Node* nuevo_nodo = new Node();
    nuevo_nodo->dato = n;

    Node* aux1 = list;
    Node* aux2 = NULL;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->Next;
    }

    if (list == aux1) {
        list = nuevo_nodo;
    }
    else {
        aux2->Next = nuevo_nodo;
    }

    nuevo_nodo->Next = aux1;
    cout << "\tElemento " << n << " ha sido agregado a la lista correctamente\n";
}

//Funcion para mostrar lista
void showList(Node* list) {
    Node* actual = new Node();
    actual = list;
    cout << "La lista es:" << endl;
    while (actual != NULL) {

        cout << actual->dato << " -> ";
        actual = actual->Next;
    }
}

//Funcion para buscar elemento en la lista
void findList(Node* list, int n) {
    bool band = false;

    Node* actual = new Node; //declarando nodo
    actual = list; //Nodo actual senala la primera posicion de la lista

    while ((actual != NULL) && (actual->dato <= n)) {
        if (actual->dato == n) {//este if es para determinar si el elemento existe o no en la lista
            band = true;
        }
        actual = actual->Next;//si no se encuentra el elemento, pues sigue buscando por los demas elementos
    }
    if (band == true) { //si entro al if de arriba
        cout << "Elemento " << n << " SI ha sido encontrado en la lista\n";
    }
    else {//significa que si no entro al if, osea que no esta en la lista
        cout << "Elemento " << n << " NO ha sido encontrado en la lista\n";
    }
}

//Funcion para eliminar un elemento de la lista
void deleteNode(Node*& list, int n)
{
    //Preguntar si la lista esta vacia
    if (list != NULL) {
        Node* aux_borrar; //Se crean 2 nodos auxiliares
        Node* anterior = NULL;

        aux_borrar = list;
        //Recorrer la lista
        while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->Next; //Se mueve una posicion mas en la lista
        }
        //3 condicionales para 3 casos diferentes
        //Caso 1, el elemento no ha sido encontrado
        if (aux_borrar == NULL) {
            cout << "El elemento no existe en la lista";
        }
        //El primer elemento es que se va a eliminar
        else if (anterior == NULL) {
            list = list->Next;
            delete aux_borrar;
        }
        //El elemento esta en la lista, pero no es el primer nodo
        else {
            anterior->Next = aux_borrar->Next;
            delete aux_borrar;
        }
    }
}

//Funcion para eliminar  la lista
void deleteList(Node*& list, int& n)
{
    Node* aux = list; //Crear un nodo auxiliar
    n = aux->dato; //Guardar elemento antes de eliminar el nodo
    list = aux->Next; //Como se eliminar el primer elemento de la lista, pues lista apunta al siguiente nodo
    delete aux;

}