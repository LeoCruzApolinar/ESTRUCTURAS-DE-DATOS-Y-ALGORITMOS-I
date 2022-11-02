/*
Enunciado    :    Los Cubos Narcisistas
Equipo       :
Participantes:    Adrian Bastardo        ID:  1105264
				  Alexa  Guzmán          ID:  1101488
				  José L. Cruz           ID:  1106529
				  Eros Bencosme          ID:  1104510
Fecha        :    15/08/2022
Materia      :    Laboratorio Estructura de Datos y Algoritmos I
Profesor     :    Casimiro Gilberto Cordero Ramirez
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "\n¡Bienvenido al programa de los cubos narcisistas!" << endl;
	cout << "Este programa consiste en decir si el número de tres dígitos es narcisista o no. \nSon cubos narcisistas aquellos números positivos que son exactamente iguales a la suma de sus dígitos elevados al cubo." << endl << endl;
	cout << "Presione Enter para ver los cubos narcisistas del 0 al 1000" << endl;
	cin.ignore();

	for (int i = 100; i < 1000; i++) { // Asigna el valor inicial a 100 y especifica que debe incrementarse hasta llegar a 1000
		a = i % 10; // Busca el último dígito del número
		b = i / 10 % 10; // Busca el segundo dígito del número
		c = i / 100 % 10; // Busca el primer digito del número

		if (i == (a * a * a + b * b * b + c * c * c)) // Comprueba si el acumulador es un número narcisista al sumar cada dígito al cubo
			cout << i << endl;
	}

}