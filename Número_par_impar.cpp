#include <iostream> // Incluye la biblioteca para entrada y salida de datos
#include <cstdlib> // Incluye funciones generales de C++

using namespace std; // Permite utilizar cout y cin sin escribir std::

int main() // Función principal del programa
{ // Inicio del programa
    int numero; // Declara una variable entera para guardar el número

    cout << "Ingrese un numero: "; // Solicita un número al usuario
    cin >> numero; // Guarda el número ingresado

    if (numero % 2 == 0) // Comprueba si el residuo de dividir entre 2 es cero
    { // Inicio de la condición
        cout << "El numero es par." << endl; // Muestra que el número es par
    } // Fin de la condición
    else // Se ejecuta cuando el número no es par
    { // Inicio del bloque else
        cout << "El numero es impar." << endl; // Muestra que el número es impar
    } // Fin del bloque else

    return 0; // Finaliza el programa correctamente
} // Fin del programa