#include <iostream> 
#include <cstdlib> // Incluye funciones para generar números aleatorios
#include <ctime> // Incluye funciones relacionadas con el tiempo

using namespace std; 
int main() 
{ // Inicio del programa
    int numero; // Declara una variable para guardar el número aleatorio

    srand(time(0)); // Inicializa el generador de números aleatorios

    numero = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100

    cout << "Numero aleatorio: " << numero << endl; // Muestra el número generado

    return 0; // Finaliza el programa correctamente
} // Fin del programa