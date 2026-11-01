#include<iostream>
using namespace std;
int main () {
float base, altura, area;
float perimetro;
cout << "ingrese  la base del rectangulo: ";
cin >> base;
cout << "ingrese la altura del rectangulo: ";
cin >> altura;

area = base * altura;
perimetro = (base + altura ) * 2;

cout<<"El area del rectangulo es :  "<< area<<endl;
cout<<"El perimetro es del rectangulo  "<<perimetro<<endl;


    return 0;
}