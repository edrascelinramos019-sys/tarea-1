/*  
Conversión de tiempo

Solicita una cantidad de minutos y conviértela a horas completas y minutos restantes.

Ejemplo: 135 minutos → 2 horas y 15 minutos. Usa / y %.
*/
#include<iostream>
using namespace std;
int main(){
    int minutos;
    int horas; 
    cout<<"Ingrese la cantidad de minutos ";
    cin>>minutos;
horas = minutos/60;
int minutosRestantes = minutos % 60;
 cout<<"Equivale a: "<<horas<<" hora(s) "<<" y "<<minutosRestantes<<" minutos"<<endl; 




    return 0;
}