/*
Enunciado    :    Queues
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
#include <queue>
using namespace std;

struct node {
    int dato;
    node* next;
    int priori;
};

bool emptyQueue(node* front);

void enqueue(node*& front, node*& end, int n, int pr)
{
    node* newNode = new node(); // Creando espacio para almacenar un nodo
    newNode->dato = n; // Asignando el nuevo nodo al dato
    newNode->next = NULL;
    newNode->priori = pr; // Asignando el nuevo nodo a la prioridad


    if (emptyQueue(front)) {
        front = newNode;
    }
    else {
        end->next = newNode;
    }
    end = newNode;
}

// Funcion para determinar si la cola esta vacia
bool emptyQueue(node* front) {
    // return(front == NULL)? true : false;
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void dequeue(node*& front, node*& end, int& n) {
    n = front->dato; // Obteniendo el valor del nodo
    node* aux = front; // Creando un nodo auxiliar
    if (front == end) { // Verificando si tiene un solo nodo o no
        front = NULL;
        end = NULL;
    }
    else {
        front = front->next;
    }
    delete aux;
}

void orderPriority(node* front)
{
    node* aux1, * aux2{};
    int aux_p, aux_c;
    aux1 = front;

    while (aux1->next != NULL)
    {
        aux2 = aux1->next;
    }
    while (aux2 != NULL)
    {
        if (aux1->priori > aux2->priori)
        {
            aux_p = aux1->priori;
            aux_c = aux1->dato;

            aux1->priori = aux2->priori;
            aux1->dato = aux2->dato;

            aux2->priori = aux_p;
            aux2->dato = aux_c;
        }

        aux2 = aux2->next;
    }

    aux1 = aux1->next;
}


/*
bool insertPriority(node *&front, int priori, int n) {
  int pr = 0;
  node *aux;
  node *newNode = new node();
  bool ip = true;
  aux = front;

  while (aux != NULL && priori < pr) {
    aux = aux -> next;
    pr++;
  }
  if (priori == pr) {
    newNode -> dato = n;
    newNode -> next = aux;

    if (priori != 0) {
      aux -> next = newNode;
    }
    else {
      ip = false;

    }
  } return ip;
}
*/
void showQueue(node*& front, node*& end)
{
    node* aux;
    aux = front;
    cout << " Caracter  Prioridad " << endl;
    cout << "-------------------- " << endl;

    while (aux != NULL)
    {
        cout << "  " << aux->dato << "     |     " << aux->priori << "  " << endl;
        aux = aux->next;
    }

}

void deleteQueue(node*& front, node*& end)
{
    node* aux = front; // Creando un nodo auxiliar

    while (front != NULL)
    {
        aux = front;
        front = aux->next;
        delete aux;
    }
}

void menu() // Menu
{
    cout << "\nBienvenidos al programa de las colas/queues, a continuacion marque el numero de la funcion que desea realizar" << endl << endl;

    cout << " 1.- Agregar datos a la cola " << endl;
    cout << " 2.- Quitar datos de la cola " << endl;
    cout << " 3.- Mostrar la cola " << endl;
    cout << " 4.- Eliminar toda la cola " << endl;
    cout << " 5.- Salir del programa \n" << endl;
}

int main() {
    node* front = NULL;
    node* end = NULL;

    int num; // Numero a agregar
    int opc;
    int priori; // Numero de prioridad 
    int pr;

    do
    {
        menu(); cin >> opc;
        switch (opc)
        {
        case 1:

            cout << "\nIngrese un numero en la cola: ";
            cin >> num;
            cout << "\nIngrese la prioridad: ";
            cin >> pr;
            enqueue(front, end, num, pr);
            orderPriority(front);
            cout << "\n\nNumero " << num << " agregado!\n\n";

            break;

        case 2:

            if (front != NULL) {
                dequeue(front, end, num);
                cout << "\n\nNumero " << num << " eliminado!\n\n";
            }
            else {
                cout << "\nAun no hay numeros en la cola\n\n";
            }

            break;

        case 3:
            cout << "\nMostrando cola\n\n";
            if (front != NULL) {
                showQueue(front, end);
            }
            else {
                cout << "\nNo hay datos en la cola\n\n";
            }

            break;

        case 4:

            deleteQueue(front, end);
            cout << "\nCola eliminada!\n";
            break;
        }

    } while (opc != 5);

    return 0;
}