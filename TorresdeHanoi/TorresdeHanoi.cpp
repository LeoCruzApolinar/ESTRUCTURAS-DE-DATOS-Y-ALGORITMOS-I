/*
Enunciado    :    Torres Hanoi
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
                  Alexa  Guzmán          ID:  1101488
                  José L. Cruz           ID:  1106529
                  Eros Bencosme          ID:  1104510
Fecha        :    03/10/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <iostream>

using namespace std;

//Prototipo de funciones
void menu();
void Jugada(int disco, char a, char b, char c);
int movimientos;

//Funcion del juego
void Jugada(int disco, char a, char b, char c)
{
    if (disco == 1) //Cuando solamente sea un disco, no dependera de la recursividad y 
        //solamente bastara con mover el disco al destino.
    {
        cout << "Mover el disco " << disco << " de la torre " << a << ", hacia la torre " << c << endl;
        movimientos++;
    }
    else {
        Jugada(disco - 1, a, c, b); //Disco -1: Es para que juegue con el disco siguiente mas pequeno
        //Esto sirve para evitar que se inserte un disco mas grande sobre uno pequeno

        //En este paso, todos los discos a excepcion del disco mas grande, estan en la torre auxiliar
        cout << "Mover el disco " << disco << " de la torre " << a << ", hacia la torre " << c << endl;

        Jugada(disco - 1, b, a, c); //Esta segunda llamada es para poder mover los discos de la torre
        //auxiliar hacia el destino.
        movimientos++;
    }

}

int main()
{
    menu();
}

//Funciones

//Funcion del menu
void menu() {
    int numeros, movement, opcion;
    double disco;
    char str[100]; //sirve para la validacion de datos 

    do {
        cout << "\t_.:MENU:._" << endl;
        cout << "1) Jugar torres Hanoi" << endl;
        cout << "2) Salir del juego" << endl;

        do {
            cout << "Opcion: ";
            cin >> str;

            while ((isalpha(str[0])))//Verifica si es de tipo de letra
            {
                cout << "\n\nPor favor, ingrese un numero la opcion 1 o la opcion 2 y por favor no use letras\n";
                cout << "Opcion: ";
                cin >> str;
            };
            opcion = atoi(str); // Convierte la variable str a tipo int
            if (opcion > 2 || opcion < 1)
            {
                cout << "\nPor favor, ingrese un numero para la opcion 1 o la opcion 2\n";

            }
        } while ((opcion > 2) || (opcion < 1));
        str[0] = NULL;

        switch (opcion) {
        case 1:
            cout << "\nInsertar la cantidad de discos con la cual desea jugar: ";
            cin >> str;
            cout << endl;
            while ((isalpha(str[0])))
            {
                cout << "Las letras no estan permitidas";
                cout << "\nInsertar la cantidad de discos con la cual desea jugar: " << endl;
                cin >> str;
                cout << endl;
            }
            numeros = atoi(str); // Convierte la variable str a tipo int
            str[0] = NULL;
            if (numeros > 65 || numeros <= 2)
            {
                cout << "El juego solo funciona con un minimo de 3 discos insertados y un maximo de 65, asi que por favor ingrese de 3 a 65 discos para poder jugar\n";
            }
            else
            {
                Jugada(numeros, 'A', 'B', 'C');
                cout << "\nLa cantidad de movimientos en total es: " << movimientos << endl;
                movimientos = 0;

            }
            cout << "\n";
            system("pause");
            break;

        case 2:
            cout << "\nSalir del programa";
            cout << "\n";
            break;
        }
        system("cls");
    } while (opcion != 2);
}