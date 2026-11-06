#include <iostream>
using namespace std;
 int calcularAreaRectangulo(int a, int b){
return a * b;


 }




int main (){
int base, altura, area;

cout<<"Ingrese la base del rectangulo: ";
cin>> base; 
cout<< "Ingrese la altura del rectangulo: ";
cin>> altura;
 
area = calcularAreaRectangulo(base, altura);

cout<<"El area del rectangulo es: "<<area<<endl; 
    return 0; 
    
}