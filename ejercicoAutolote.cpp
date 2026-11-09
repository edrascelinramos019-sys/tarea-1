#include<iostream>
#include<string>
#include<cctype>
#include <iomanip> 
using namespace std;  

// ---------- PRECIOS ----------
const double PRECIO1 = 280000;  // Toyota Corolla 2020
const double PRECIO2 = 320000;  // Honda Civic 2021
const double PRECIO3 = 350000;  // Hyundai Elantra 2022
const double PRECIO4 = 550000;  // Toyota Hilux 2020
const double PRECIO5 = 620000;  // Ford Ranger 2021
const double PRECIO6 = 680000;  // Mitsubishi L200 2022
const double PRECIO7 = 850000;  // Ford Mustang 2019
const double PRECIO8 = 950000;  // Chevrolet Camaro 2020
const double PRECIO9 = 780000;  // Nissan 370Z 2018
const double ISV = 0.15;
 
// ---------- CARRITO (true = vehiculo agregado) ----------
bool enCarrito1 = false, enCarrito2 = false, enCarrito3 = false;
bool enCarrito4 = false, enCarrito5 = false, enCarrito6 = false;
bool enCarrito7 = false, enCarrito8 = false, enCarrito9 = false;
 
// ---------- FUNCIONES AUXILIARES ----------
void agregarAlCarrito(bool &enCarrito, string nombre) {
	if (enCarrito) {
		cout << nombre << " ya esta en el carrito.\n";
	} else {
		enCarrito = true;
		cout << "Has agregado " << nombre << " al carrito\n";
	}
}
 
// Imprime la linea si el vehiculo esta en el carrito y devuelve su precio (0 si no esta)
double lineaCarrito(bool enCarrito, int codigo, string nombre, double precio) {
	if (!enCarrito) return 0;
	cout << codigo << ". " << nombre << " - L. " << fixed << setprecision(2) << precio << "\n";
	return precio;
}
 
double mostrarLineas() {
	double subtotal = 0;
	subtotal += lineaCarrito(enCarrito1, 1, "Toyota Corolla 2020", PRECIO1);
	subtotal += lineaCarrito(enCarrito2, 2, "Honda Civic 2021", PRECIO2);
	subtotal += lineaCarrito(enCarrito3, 3, "Hyundai Elantra 2022", PRECIO3);
	subtotal += lineaCarrito(enCarrito4, 4, "Toyota Hilux 2020", PRECIO4);
	subtotal += lineaCarrito(enCarrito5, 5, "Ford Ranger 2021", PRECIO5);
	subtotal += lineaCarrito(enCarrito6, 6, "Mitsubishi L200 2022", PRECIO6);
	subtotal += lineaCarrito(enCarrito7, 7, "Ford Mustang 2019", PRECIO7);
	subtotal += lineaCarrito(enCarrito8, 8, "Chevrolet Camaro 2020", PRECIO8);
	subtotal += lineaCarrito(enCarrito9, 9, "Nissan 370Z 2018", PRECIO9);
	return subtotal;
}
 
void vaciarCarrito() {
	enCarrito1 = enCarrito2 = enCarrito3 = false;
	enCarrito4 = enCarrito5 = enCarrito6 = false;
	enCarrito7 = enCarrito8 = enCarrito9 = false;
}
 
// ---------- MENUS ----------
void menuSedanes() {
	int opcion;
	do {
		cout << "\nSEDANES\n";
		cout << "1. Toyota Corolla 2020 - L. 280,000\n";
		cout << "2. Honda Civic 2021 - L. 320,000\n";
		cout << "3. Hyundai Elantra 2022 - L. 350,000\n";
		cout << "4. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarAlCarrito(enCarrito1, "Toyota Corolla 2020");
			break;
		case 2:
			agregarAlCarrito(enCarrito2, "Honda Civic 2021");
			break;
		case 3:
			agregarAlCarrito(enCarrito3, "Hyundai Elantra 2022");
			break;
		case 4:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);
}
 
void menuCamionetas() {
	int opcion;
	do {
		cout << "\nCAMIONETAS\n";
		cout << "1. Toyota Hilux 2020 - L. 550,000\n";
		cout << "2. Ford Ranger 2021 - L. 620,000\n";
		cout << "3. Mitsubishi L200 2022 - L. 680,000\n";
		cout << "4. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarAlCarrito(enCarrito4, "Toyota Hilux 2020");
			break;
		case 2:
			agregarAlCarrito(enCarrito5, "Ford Ranger 2021");
			break;
		case 3:
			agregarAlCarrito(enCarrito6, "Mitsubishi L200 2022");
			break;
		case 4:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);
}
 
void menuDeportivos() {
	int opcion;
	do {
		cout << "\nDEPORTIVOS\n";
		cout << "1. Ford Mustang 2019 - L. 850,000\n";
		cout << "2. Chevrolet Camaro 2020 - L. 950,000\n";
		cout << "3. Nissan 370Z 2018 - L. 780,000\n";
		cout << "4. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarAlCarrito(enCarrito7, "Ford Mustang 2019");
			break;
		case 2:
			agregarAlCarrito(enCarrito8, "Chevrolet Camaro 2020");
			break;
		case 3:
			agregarAlCarrito(enCarrito9, "Nissan 370Z 2018");
			break;
		case 4:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);
}
 
void carritoCompra() {
	int opcion;
	do {
		cout << "\nCARRITO DE COMPRA\n";
		cout << "1. Ver carrito\n";
		cout << "2. Facturar\n";
		cout << "3. Regresar al menu principal\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			cout << "\nProductos comprados\n";
			double subtotal = mostrarLineas();
			if (subtotal == 0) {
				cout << "El carrito esta vacio.\n";
			} else {
				cout << "Subtotal: L. " << fixed << setprecision(2) << subtotal << "\n";
			}
			break;
		}
		case 2: {
			cout << "\n========== FACTURA ==========\n";
			double subtotal = mostrarLineas();
			if (subtotal == 0) {
				cout << "No hay vehiculos para facturar.\n";
			} else {
				double impuesto = subtotal * ISV;
				cout << "-----------------------------\n";
				cout << "Subtotal:  L. " << fixed << setprecision(2) << subtotal << "\n";
				cout << "ISV (15%): L. " << impuesto << "\n";
				cout << "TOTAL:     L. " << subtotal + impuesto << "\n";
				vaciarCarrito();
			}
			cout << "=============================\n";
			break;
		}
		case 3:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 3);
}



int main () {

string nombre;
    bool valido = true;

    do {
        valido = true;

        cout << "Ingrese su nombre: ";
        getline(cin, nombre);

        // Comprobar que todos los caracteres sean letras o espacios
        for (int i = 0; i < nombre.length(); i++) {

            if (!isalpha(nombre[i]) && nombre[i] != ' ') {
                valido = false;
                break;
            }
        }

        if (!valido) {
            cout << "Error: El nombre no puede contener numeros ni simbolos.\n";
        }

    } while (!valido);

    cout << "Nombre registrado correctamente: " << nombre;



char sexoCliente;
cout<<"  Ingrese su sexo (M/F): ";
cin>>sexoCliente;
while (sexoCliente != 'm' && sexoCliente != 'M' && sexoCliente != 'f' && sexoCliente != 'F') {
        cout << "Error: Caracter no valido. Por favor, ingrese solo m, M, f o F: ";
        cin >> sexoCliente;
}

int edadCliente;

cout << "Ingrese su edad: ";
cin >> edadCliente;

while (cin.fail() || edadCliente < 18 || edadCliente > 100) {

    if (cin.fail()) {
        cout << "Error: Debe ingresar solamente numeros. Ingrese su edad: ";

        cin.clear();
        cin.ignore(1000, '\n');
    }
    else {
        cout << "Error: Edad fuera de rango. Ingrese una edad entre 18 y 100: ";
    }

    cin >> edadCliente;
}

long long numeroIdentificacionCliente;
cout<< "ingrese su numero de identificacion: "; 
cin >> numeroIdentificacionCliente;


    int tipoCliente;
cout<<"Ingrese el tipo de cliente "<<endl;
cout<<"1. Para  clienteVIP (5% de descuento en cualquier vehiculo)   "<<endl;
    cout<<"2. Para clienteFrecuente (3% de descuento en cualquier vehiculo)   "<<endl;
cout<<"3.  Para clienteNuevo (sin descuento)   "<<endl; 
    cin >> tipoCliente;

    while (tipoCliente < 1 || tipoCliente > 3) {
        cout << "Error: Tipo de cliente no valido. Por favor, ingrese un valor entre 1 y 3: ";
        cin >> tipoCliente;
}

if (tipoCliente == 1) {
        cout << "Tipo de cliente registrado correctamente: clienteVIP" << endl;
    } else if (tipoCliente == 2) {
        cout << "Tipo de cliente registrado correctamente: clienteFrecuente" << endl;
    } else if (tipoCliente == 3) {
        cout << "Tipo de cliente registrado correctamente: clienteNuevo" << endl;
    } else {
        cout << "Tipo de cliente registrado correctamente: Desconocido" << endl;
    }




  return 0;
}

