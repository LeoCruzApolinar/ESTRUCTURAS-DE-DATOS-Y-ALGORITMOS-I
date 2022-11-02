/*
Enunciado    :    Reina vs Torres gemelas
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
                  Alexa  Guzmán          ID:  1101488
                  José L. Cruz           ID:  1106529
                  Eros Bencosme          ID:  1104510
Fecha        :    10/10/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <iostream>
#include <windows.h>

using namespace std;

//Prototipos
void Posiciones();
void Movimiento(int, int, int, int, int, int);
int numeros;
void titulo();
void Color(int color); //Colorea el texto.
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//variable para colores.

int main() {
    //declaracion de variables
    int opcion;
    string letra;


    do {  //Menu del juego
        titulo();
        bool vf = false; // Validacion
        do
        {
            vf = false;
            int o = 0;
            cout << "Elija una opcion:\n";
            cin >> letra;
            int n = letra.size();
            for (int i = 0; i < n; i++)
            {
                if (isalpha(letra[i])) { // Verifica si cada caracter del string es una letra o no
                    vf = true;
                    o = o + 1;
                    if (o == 1)
                    {
                        Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                    }
                }
            }
        } while (vf == true); // Se repetira el ciclo mientras vf sea true
        char* c10 = const_cast<char*>(letra.c_str()); // Convierte el string a char
        opcion = atoi(c10);// convierte el char en entero


        switch (opcion)
        {
        case 1:
            Posiciones(); //funcion para ingresar posiciones de R,T,T

            cout << "\n";
            system("pause");
            break;
        case 2:  //para salir del juego

            Color(3); cout << "\nHasta la proxima!\n" << endl; Color(7);
            system("pause");
            break;
        default:  //si se escoge una opcion incorrecta
            cout << "La opcion que escogiste no esta disponible, intente de nuevo\n";
            cout << "\n";
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 2);
    return 0;
}


void Posiciones() {  //funcion para ingresar las posiciones de R,T,T
    int x, y, x1, y1, x2, y2;  //xy para R, x1y1 para T, x2y2 para T
    string a1, a2, a3, a4, a5, a6; // Diagonales de la reina

    //posiciones para la reina
    bool esc = false;
    do // Verificacion de letras
    {
        int o = 0;
        esc = false;
        cout << "\nIngrese la fila de la reina: ";
        cin >> a1;
        int n = a1.size();

        for (int i = 0; i < n; i++)
        {
            if (isalpha(a1[i]))// Si el digito que introducimos es una letra
            {
                esc = true;//verifica que hay un error
                o = o + 1;
                if (o == 1)
                {
                    Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                }
            }
        }

    } while (esc == true); // Se repetira el ciclo mientras vf sea true
    char* c1 = const_cast<char*>(a1.c_str()); // Convierte el string a char
    x = atoi(c1); // Convierte el char en entero

    // Esta funcion se va a aplicar en los demas introducir numero
    do
    {
        int o = 0;
        esc = false;
        cout << "Ingrese la columna de la reina: ";
        cin >> a2;
        int n = a2.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(a2[i]))
            {

                esc = true;
                o = o + 1;
                if (o == 1)
                {
                    Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                }

            }
        }
    } while (esc == true);
    char* c2 = const_cast<char*>(a2.c_str());
    y = atoi(c2);//convierte el char en entero
    do
    {
        int o = 0;
        esc = false;
        cout << "\nIngrese la fila de la primera torre: ";
        cin >> a3;
        int n = a3.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(a3[i]))
            {

                esc = true;
                o = o + 1;
                if (o == 1)
                {
                    Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                }
            }

        }
    } while (esc == true);
    char* c3 = const_cast<char*>(a3.c_str());
    x1 = atoi(c3);//convierte el char en entero
    do
    {
        int o = 0;
        esc = false;
        cout << "Ingrese la columna de la primera torre: ";
        cin >> a4;
        int n = a4.size();
        for (int i = 0; i < n; i++)
        {

            if (isalpha(a4[i]))
            {
                esc = true;
                o = o + 1;
                if (o == 1)
                {
                    Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                }

            }
        }
    } while (esc == true);
    char* c4 = const_cast<char*>(a4.c_str());
    y1 = atoi(c4);//convierte el char en entero
    do
    {
        int o = 0;
        esc = false;
        cout << "\nIngrese la fila de la segunda torre: ";
        cin >> a5; int n = a4.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(a5[i]))
            {

                esc = true;
                o = o + 1;
                if (o == 1)
                {
                    Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                }

            }
        }
    } while (esc == true);
    char* c5 = const_cast<char*>(a5.c_str());
    x2 = atoi(c5);//convierte el char en entero

    do
    {
        int o = 0;
        esc = false;
        cout << "Ingrese la columna de la segunda torre: ";
        cin >> a6;
        int n = a6.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(a6[0]))
            {
                Color(4); cout << "\nLas letras no estan permitidas\n" << endl; Color(7);
                esc = true;

            }
        }

    } while (esc == true);
    char* c6 = const_cast<char*>(a6.c_str());
    y2 = atoi(c6);//convierte el char en entero

    //si alguna posicion pasa el limite del tablero
    if (x < 1 || x > 8 || y < 1 || y > 8 || x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        Color(4); cout << "\nHa ingresado posiciones fuera del tablero, intentelo nuevamente.\n"; Color(7);
    }
    //si se ingreso en una posicion donde apuntan las torres.
    else if (x == x1 || x == x2 || y == y1 || y == y2) {
        Color(4); cout << "\nLa reina cayo en una x, perdiste!\n\n"; Color(7);
        system("pause");
    }

    //Si las torres estan en la misma posicion
    else if (x1 == x2 && y1 == y2) {
        Color(4); cout << "\nNo puedes poner las torres en una misma posicion!" << endl; Color(7);
    }

    //sino se mandan las posiciones a Movimiento()
    else {
        Movimiento(x - 1, y - 1, x1 - 1, y1 - 1, x2 - 1, y2 - 1);//se le resta uno para usarlo como indice en los arreglos, para que vaya de 0 a 7.
    }
}

//funcion para posicionar y mostrar todo
void Movimiento(int x, int y, int x1, int y1, int x2, int y2) {
    char recorrer[8][8];  //arreglo para darle valor a las casillas

    //Recorre desde [0][0] a [8][8] llenando las casillas
    for (int filas = 0; filas < 8; filas++) {
        for (int columnas = 0; columnas < 8; columnas++) {
            if (filas == x && columnas == y) {  // Si filas y columnas es igual a xy
                recorrer[filas][columnas] = 'R';  // Es la reina
            }
            else if ((filas == x1 && columnas == y1) || (filas == x2 && columnas == y2)) {
                recorrer[filas][columnas] = 'T';  //es una torre
            }
            //si filas y columnas es apuntada por la reina y por alguna torre
            else if ((x == filas && columnas == y1) || (x == filas && columnas == y2) || (x1 == filas && columnas == y) || (x2 == filas && columnas == y)) {
                recorrer[filas][columnas] = 'X';  //intercepta una torre
            }
            //Si filas y columnas esta en una fila o columna de la reina
            else if (filas == x || columnas == y) {
                recorrer[filas][columnas] = 'V';  //se puede mover
            }
            else {
                recorrer[filas][columnas] = ' '; //casilla vacia
            }
        }

        //Recorre en diagonal desde la reina hacia los limites
        for (int a = x, b = y; a < 8 && b < 8; a++, b++) { // Inferior derecha
            //Si no es ni Torre ni Reina
            if (recorrer[a][b] != 'T' && recorrer[a][b] != 'R') {
                recorrer[a][b] = 'V';
            }
            //Si se intercepta con una torre  
            if (((b == y1) || (b == y2) || (x1 == a) || (x2 == a)) && recorrer[a][b] != 'T') {
                recorrer[a][b] = 'X';
            }
        }

        //Recorre en diagonal desde la reina hacia los limites
        for (int a = x, b = y; a >= 0 && b >= 0; a--, b--) { // Superior izquierda
            //Si no es ni Torre ni Reina
            if (recorrer[a][b] != 'T' && recorrer[a][b] != 'R') {
                recorrer[a][b] = 'V';
            }
            //Si se intercepta con una torre
            if (((b == y1) || (b == y2) || (x1 == a) || (x2 == a)) && recorrer[a][b] != 'T') {
                recorrer[a][b] = 'X';
            }
        }

        //Recorre en diagonal desde la reina hacia los limites
        for (int a = x, b = y; a >= 0 && b < 8; a--, b++) { // Superior derecha
            //Si no es ni Torre ni Reina
            if (recorrer[a][b] != 'T' && recorrer[a][b] != 'R') {
                recorrer[a][b] = 'V';
            }
            //Si se intercepta con una torre
            if (((b == y1) || (b == y2) || (x1 == a) || (x2 == a)) && recorrer[a][b] != 'T') {
                recorrer[a][b] = 'X';
            }
        }

        //Recorre en diagonal desde la reina hacia los limites
        for (int a = x, b = y; a <= 8 && b >= 0; a++, b--) { // Inferior izquierda
            //Si no es ni Torre ni Reina
            if (recorrer[a][b] != 'T' && recorrer[a][b] != 'R') {
                recorrer[a][b] = 'V';
            }
            //Si se intercepta con una torre
            if (((b == y1) || (b == y2) || (x1 == a) || (x2 == a)) && recorrer[a][b] != 'T') {
                recorrer[a][b] = 'X';
            }
        }
    }
    cout << "\n    A   B   C   D   E   F   G   H ";//poner letras en la fila superior de la tabla
    //mostrar

    for (int filas = 0; filas < 8; filas++) {
        cout << "\n  ---------------------------------\n"; //diseño del tablero

        numeros++;//poner numeros de la columna lateral izquierdo de la tabla
        cout << numeros;

        for (int columnas = 0; columnas < 8; columnas++) {

            if (recorrer[filas][columnas] == 'R') {
                cout << " | "; Color(4); cout << recorrer[filas][columnas]; Color(7);
            }
            else if (recorrer[filas][columnas] == 'T') {
                cout << " | "; Color(9); cout << recorrer[filas][columnas]; Color(7);
            }
            else if (recorrer[filas][columnas] == 'X') {
                cout << " | "; Color(6); cout << recorrer[filas][columnas]; Color(7);
            }
            else if (recorrer[filas][columnas] == 'V') {
                cout << " | "; Color(2); cout << recorrer[filas][columnas]; Color(7);
            }
            else {
                cout << " | " << recorrer[filas][columnas];  //mostrar contenido de la casilla
            }
        }
        cout << " |";  //diseño del tablero
    }
    cout << "\n  ---------------------------------\n";//diseño del tablero
    numeros = 0;
}

void Color(int color) {//funcion para dar colores a las letras
    SetConsoleTextAttribute(h, color);
}

void titulo() {//funcion titulo, se llama en el menu y se queda fijo
    system("cls");
    Color(95); cout << "*******************************" << endl;
    cout << "    REINA VS TORRES GEMELAS    " << endl;
    cout << "*******************************\n" << endl; Color(7);
    Color(6); cout << "\t  *MENU*" << endl; Color(7);
    cout << "\t [1].Jugar" << endl;
    cout << "\t [2].Salir\n" << endl;

}