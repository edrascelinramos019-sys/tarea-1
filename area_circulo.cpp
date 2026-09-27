#include <iostream> 
using namespace std;

int main() 
{ // Inicio del programa
    double radio; // Declara una variable para guardar el radio
    const double PI = 3.14159265359; // Declara el valor aproximado de PI

    cout << "Ingrese el radio del circulo: "; // Solicita el radio al usuario
    cin >> radio; // Guarda el radio ingresado

    double area = PI * radio * radio; // Calcula el área del círculo

    cout << "El area del circulo es: " << area << endl; // Muestra el resultado

    return 0; 
} // Fin del programa