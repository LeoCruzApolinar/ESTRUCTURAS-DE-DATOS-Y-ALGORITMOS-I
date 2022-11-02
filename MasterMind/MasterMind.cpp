/*
Enunciado    :    Realizar un Juego MasterMind en modalidad principiante
Equipo       :
Participantes:    Adrian Bastardo         ID:  1105264
                  Alexa  Guzmán           ID:  1101488
                  José L. Cruz            ID:  1106529
                  Eros Bencosme           ID:  1104510
Fecha        :    15/08/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <iostream>
using namespace std;
int main() {
    char str[1];
    int i;               // Variable de incremento (ES UN COMODIN)
    int N;               // Variable de incremento (ES UN COMODIN)
    int Arreglo[4];      // Guarda lo que ingresa el usuario
    int random[4] = { 0 }; // Guarda los números aleatorios
    bool WN = false;
    int intentos = 0; // Variable de incremento (ES UN COMODIN)
    int calificacion = 10;

    srand(time(0)); // Función para generar números aleatorios

    cout << "\n¡Bienvenido a MasterMind!\nTendrás 10 intentos para acertar 4 "
        "dígitos del 1 al 6.\n"
        << endl;
    cout << "[C] Significa que el número es correcto y está ubicado "
        "correctamente. \n[F] Significa que el números está en el arreglo "
        "pero en la posición incorrecta. \n[X] Significa que el número no "
        "está en el arreglo."
        << endl
        << endl;
    cout << "Presione Enter para comenzar";
    cin.ignore();

    do {
        for (i = 0; i < 4; ++i) {
            random[i] = 1 + rand() % (7 - 1);
        }
        // Para que los dígitos aleatorios del arreglo no se repitan
    } while (random[0] == random[1] || random[2] == random[3] ||
        random[3] == random[1] || random[2] == random[0] ||
        random[3] == random[0] || random[2] == random[1]);
    do {
        cout << "\nIntroduzca 4 dígitos" << endl;
        ++intentos;
        cout << "Intento " << intentos << endl << endl;
        // Para que los intentos no excedan de 10
        if (intentos > 10) {
            cout << "Se han agotado los intentos" << endl;
            cout << "Lo siento, no ha logrado acertar el código" << endl;
            exit(-1);
        }
        /*Para mostrar los números escogidos aleatoriamente:
        for (i = 0; i < 4; ++i) {
                cout << "arreglo[" << i << "] = " << random[i];
                cout << "\n";
        } */

        // Evita los numeros mayores a 6 y el uso de letras
        for (i = 0; i < 4; ++i) {
            do {
                cout << "Numero " << i + 1 << ":" << endl;
                cin >> str;
                while (isalpha(str[0])) {
                    cout << "El uso de letras no es posible favor e ingrese un número"
                        << endl;
                    cout << "Número " << i + 1 << ":" << endl;
                    cin >> str;
                }
                N = atoi(str);

                if (N > 6 || N < 1) {
                    cout << "Ha introducido un valor fuera del rango establecido, inténtelo otra vez."
                        << endl;
                }
                else {
                    Arreglo[i] = N;
                }
            } while (N > 6 || N < 1);
        }

        // Compara los valores de los arreglos para verificar su igualdad
        for (N = 0; N < 4; ++N) {
            for (i = 0; i < 4; ++i) {

                if (Arreglo[N] == random[i]) {
                    if (N == i) {
                        cout << "El número " << Arreglo[N] << " [C]" << endl;
                        break;

                    }
                    else {
                        cout << "El número " << Arreglo[N] << " [F]" << endl;
                        break;
                    }
                    break;
                }
                else if (i == 3) {
                    cout << "El número " << Arreglo[N] << " [x]" << endl;
                }
            }
        }
        // Permite cerrar el programa al cumplirse las condiciones
        if (Arreglo[0] == random[0] && Arreglo[1] == random[1] &&
            Arreglo[2] == random[2] && Arreglo[3] == random[3]) {
            WN = true;
            cout << "¡Felicidades, ha acertado el código!" << endl;
            calificacion = 10 - intentos;
            cout << "Su calificación es: " << calificacion << "/10" << endl;
        }
    } while (WN == false);
}