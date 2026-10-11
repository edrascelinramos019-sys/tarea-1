#include <iostream>
#include <string>

using namespace std;

int main() {

    
    string nombre;
    float parcial1, parcial2, parcial3;
    float promedio;
    string ponderacion;

    
    for (int i = 1; i <= 5; i++) {

        cout << "\n===== ESTUDIANTE " << i << " =====" << endl;

       
        cout << "Ingrese el nombre: ";
        cin>>nombre;

        
        cout << "Ingrese nota del I Parcial (25%): ";
        cin >> parcial1;

        cout << "Ingrese nota del II Parcial (35%): ";
        cin >> parcial2;

        cout << "Ingrese nota del III Parcial (40%): ";
        cin >> parcial3;

        /
        promedio = (parcial1 * 0.25) +
                   (parcial2 * 0.35) +
                   (parcial3 * 0.40);

        
        if (promedio >= 90) {
            ponderacion = "Sobresaliente";
        }
        else if (promedio >= 80) {
            ponderacion = "Notable";
        }
        else if (promedio >= 70) {
            ponderacion = "Aprobado";
        }
        else if (promedio >= 60) {
            ponderacion = "Regular";
        }
        else {
            ponderacion = "Reprobado";
        }

        
        cout << "\n----- RESULTADO -----" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "I Parcial: " << parcial1 << endl;
        cout << "II Parcial: " << parcial2 << endl;
        cout << "III Parcial: " << parcial3 << endl;
        cout << "Promedio Final: " << promedio << endl;
        cout << "Ponderacion: " << ponderacion << endl;
    }

    return 0;
}
