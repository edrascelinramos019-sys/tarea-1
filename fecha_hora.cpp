#include <iostream> 
#include <chrono> // Incluye funciones para trabajar con tiempo

using namespace std; 
int main() { // Inicio del programa
    auto ahora = chrono::system_clock::now(); // Obtiene la fecha y hora actual del sistema

    auto tiempo = chrono::system_clock::to_time_t(ahora); // Convierte el tiempo a un formato estándar

    cout << "Fecha y hora actual: " << ctime(&tiempo); // Muestra la fecha y hora actual

    return 0; 
} // Fin del programa