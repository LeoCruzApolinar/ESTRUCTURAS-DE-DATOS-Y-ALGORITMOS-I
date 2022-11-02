/*
Enunciado    :    Frecuencia del alfabeto
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
                  Alexa  Guzmán          ID:  1101488
                  José L. Cruz           ID:  1106529
                  Eros Bencosme          ID:  1104510
Fecha        :    12/09/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include<sstream>
#include <regex>
#include <iomanip>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::setprecision;
using namespace std;

//Variables
string direccion; // Guarda la ubicacion del archivo txt 
stringstream Archivo; // Guarda el texto para luego ser convertido a string
string ArchivoTxT; //Texto guardado en el string
ifstream inputfile; //Realiza conexion con el txt
string filename; // Nombre del archivo
int NumeL; // Guarda la cantidad de letras para luego ser utilizada de manera publica

//Diccionario V
stringstream DArchivo; // Guarda el texto para luego ser convertido a string, el de diccionario contiene los caracteres reemplazar
string DArchivoTxT; // Guarda los caracteres a reemplazar en un string
stringstream SArchivo; // Guarda los caracteres sustitutos para luego ser llevados a string
string SArchivoTxT; // Se guardan los caracteres sustitutos en string
string LeerArchivo;

void Conexion() {
    ifstream Tex; // Nombre de la conexion
    Tex.open(direccion); // Abre la conexion con el archivo de texto
    Archivo << Tex.rdbuf(); // Retorna un puntero, normaliza el texto
    ArchivoTxT = Archivo.str(); // Se guarda en la variable string
    LeerArchivo = ArchivoTxT; // Se guarda el archivo antes de ser sustituido y normalizado
    cout << LeerArchivo << endl; // Muestra el txt con acentos
}
void diccionario() {
    //Caracter Comparador
    ifstream Diccionario; // Nombre de la conexion
    Diccionario.open("Diccionario.txt"); // Abre la conexion con el archivo de diccionario
    DArchivo << Diccionario.rdbuf(); // Retorna un puntero, normaliza el texto
    DArchivoTxT = DArchivo.str(); // Se guarda en la variable string
    //Caracter sustituto
    ifstream SDiccionario; // Nombre de la conexion
    SDiccionario.open("SDiccionario.txt"); // Abre la conexion con el archivo de sustituto
    SArchivo << SDiccionario.rdbuf(); // Retorna un puntero, normaliza el texto
    SArchivoTxT = SArchivo.str(); // Se guarda en la variable string

}

//Valida la existencia del archivo txt a traves de un bool y la funcion good
bool VArchivo(string nombre) {
    ifstream archivo(nombre.c_str());
    return archivo.good();
}

//Valida la existencia del archivo txt a travez de un bool y la funcion good
void VConexion() {
    bool go = false;
    do {
        cout << "Ingrese una direccion existente:" << endl;
        getline(cin, direccion);
        cout << endl;
        if (VArchivo(direccion))
        {
            go = true;
        }
    } while (go == false); // Se mantiene en bucle hasta que el programa cumpla los requisitos del metodo VArchivo
}

// A traves de las comparaciones de los diferentes caracteres en los distintos archivos logra encontrar 
// los caracteres iguales no deseados y se sustituyen por los deseados para la normalizacion del texto
void Conversion() {
    int n = ArchivoTxT.size(); // Guarda el tamaño del archivo de texto
    int s = DArchivoTxT.size(); // Guarda el tamaño del archivo diccionario
    for (int i = 0; i < s; i += 2) // Aumenta hasta ser mayor que el tamaño del archivo de texto
    { // Permite realizar la comparacion entre los diferentes caracteres
        int ni = i + 1;
        int m = i + ni;
        int g = 0;
        if (i > 0)
        {
            g = i / 2;
        }
        for (int l = 0; l < n; l++)
        {
            int nl = l + 1;
            // Se compara el valor dentro de los arreglos a traves de los indices, los cuales cambian por el bucle e incrementador
            if (ArchivoTxT[l] == DArchivoTxT[i] && ArchivoTxT[nl] == DArchivoTxT[ni])
            {

                ArchivoTxT[l] = SArchivoTxT[g];
                ArchivoTxT[nl] = NULL;
            }
        }
    }
}

// Cuenta la cantidad de palabras
void Npalabras() {
    int i, contPalabras = 0; // Contador de palabras que empieza desde 1
    int n = LeerArchivo.size(); // Contiene el tamaño del string
    char signs[4] = { ' ','!',';',',' };// Caracteres usados para tomar en cuenta el conteo de las palabras

    for (i = 0; i < n; i++) { // Para que los valores del if cambien y se puedan comparar todos

        for (int m = 0; m < 4; m++) {
            int k = i - 1;
            if (LeerArchivo[i] == signs[m] && i > 0 && LeerArchivo[k] != signs[m]) {
                // Si se encuentra uno de los caracteres anteriores se cuenta como palabra, siempre y cuando el caracter sigte
                //no sea igual

                contPalabras++;
            }

        }
    }
    cout << endl;
    cout << "Cantidad de palabras: " << contPalabras << endl;// Muestra el contador
    cout << endl;
}

size_t countOccurrences(char c, string& str) // Cuenta la cantidad de ocurrencias de las letras del texto
{
    size_t count = 0;
    // Cuenta las letras con tolower
    char tmp = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    for (char i : str)
        if (tolower(static_cast<unsigned char>(i)) == tmp)
            count++;

    return count;
}
void Cletras() {
    int count = 0;
    regex rx("[a-zA-Z]"); // Contiene un rango desde la  a-z, y A-Z
    for (sregex_iterator it(ArchivoTxT.cbegin(), ArchivoTxT.cend(), rx); it != sregex_iterator();
        ++it) count++;// Se cuentan los caracteres dentro del rango y el contador aumenta
    cout << "La cantidad de caracteres en el texto es de: " << count
        << endl;
    cout << endl;
    NumeL = count;// Se guarda la cantidad de letras en una variable publica

}
void Cpalabras() { //Cuenta las letras de manera individual para encontrar la frecuencia
    // Guarda las letras a buscar
    char abc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    for (int i = 0; i < 26; i++)
    {
        double nl = countOccurrences(abc[i], ArchivoTxT); // Cuenta las letras
        double ml = (nl / NumeL) * 100; // Porcentaje
        cout << "Caracter: '" << abc[i] << "' ocurrencias = " << setprecision(2) << fixed << ml << " %" << endl;
    }
}

//Metodos

int main() {
    setlocale(LC_CTYPE, ".UTF-8"); // Normaliza el uso de acentos en la consola
    VConexion(); // Valida la conexion
    Conexion(); // Realiza la conexion
    diccionario(); // Llama los archivos auxiliares
    Conversion(); // Normaliza los caracteres
    Npalabras(); // Cuenta las palabras
    Cletras(); // Cuenta las letras
    Cpalabras(); // Cuenta las palabras de manera unitaria sacando el porcentaje


    return 0;
}