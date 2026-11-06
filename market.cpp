#include<iostream>
#include<string>
using namespace std;  
int main () {
string nombreCliente;
cout<<"Ingrese su nombre: ";
getline(cin, nombreCliente);
char sexoCliente;
cout<<"Ingrese su sexo (M/F): ";
cin>>sexoCliente;
while (sexoCliente != 'm' && sexoCliente != 'M' && sexoCliente != 'f' && sexoCliente != 'F') {
        cout << "Error: Caracter no valido. Por favor, ingrese solo m, M, f o F: ";
        cin >> sexoCliente;
}
int edadCliente;
cout<<"Ingrese su edad: ";
cin>>edadCliente;
while(edadCliente < 15 or edadCliente > 100) {
        cout << "Error Edad fuera de rango. Por favor, ingrese una edad entre 15 y 100: ";
        cin >> edadCliente;

       }

int tipoCliente;
cout<<"Ingrese el tipo de cliente (1-3): ";
cin>>tipoCliente;
while(tipoCliente < 1 or tipoCliente > 3) {
        cout << "Error: Tipo de cliente no valido. Por favor, ingrese un valor entre 1 y 3: ";
        cin >> tipoCliente;
}
int diadeLaSemana;
cout<<" ingrese el dia de la semana (1-7): ";
cin >> diadeLaSemana;
while (diadeLaSemana < 1 or diadeLaSemana > 7){
    cout<<"Error: por favor ingrese un numero entre 1 y 7: ";
    cin >> diadeLaSemana;
}

    return 0;
}